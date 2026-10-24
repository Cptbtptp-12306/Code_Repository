#include <iostream>

using namespace std;

typedef long long ll;
const int N = 1e3 + 10;

int n, m, q;
ll a[N][N], f[N][N];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            cin >> a[i][j];
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1] [j - 1] + a[i][j];
        }
    }
    
    int x1, y1, x2, y2;
    while(q --)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        ll res = f[x2][y2] - f[x1 - 1][y2] - f[x2][y1 - 1] + f[x1 - 1][y1 - 1];
        cout << res << endl;
    }
    
    return 0;
}