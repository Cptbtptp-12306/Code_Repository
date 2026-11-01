#include<iostream>

using namespace std;

typedef long long ll;

const int N = 1010;

int n, m, q;
ll f[N][N];

//f[i][j] = a[i][j] - a[i - 1][j] - a[i][j - 1] + a[i - 1][j - 1]（二维差分定义）
//此处不引入a数组，故使用差分的性质即可
void insert(int x1, int y1, int x2, int y2, ll k)
{
    //二维差分的性质（右下区域全都被执行该操作）
    f[x1][y1] += k;
    f[x1][y2 + 1] -= k;
    f[x2 + 1][y1] -= k;
    f[x2 + 1][y2 + 1] += k;
}

//先原地求出差分数组，然后执行q此操作，直接求二维数组前缀和即可
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            ll x; cin >> x;
            insert(i, j, i, j, x);
        }
    }
    while(q--)
    {
        int x1, y1, x2, y2;
        ll k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        insert(x1, y1, x2, y2, k);
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            f[i][j] += f[i-1][j] + f[i][j-1] - f[i-1][j-1];
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
