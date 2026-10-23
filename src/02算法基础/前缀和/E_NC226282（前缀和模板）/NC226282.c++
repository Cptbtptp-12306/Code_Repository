#include <iostream>

using namespace std;

typedef long long LL; //提前定义LL
const int N = 1e5 + 100;

int n, m;
LL a[N], f[N];

int main()
{
    //加速
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    f[0] = 0;
    cin >> n >> m;

    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        f[i] = f[i - 1] + a[i]; //构造前缀和f数组
    }
    
    int l, r;
    while(m --)
    {
        cin >> l >> r;
        cout << f[r] - f[l - 1] << endl; //计算前缀和
    }
    
    return 0;
}