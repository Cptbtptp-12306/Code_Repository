#include <iostream>

using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
ll f[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
    {
        //无a数组的差分数组构造
        ll x;
        cin >> x;
        f[i] += x;
        f[i + 1] -= x;
    }
    
    int l, r, k;
    while(m --)
    {
        //区间处理
        cin >> l >> r >> k;
        f[l] += k, f[r + 1] -= k;
    }
    for(int i = 1; i <= n; i ++)
    {
        //原地前缀和，不引入其余变量
        f[i] += f[i - 1];
        cout << f[i] << " ";
    }
    return 0;
}