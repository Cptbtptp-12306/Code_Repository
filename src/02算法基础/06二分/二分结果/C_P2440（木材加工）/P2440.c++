#include <iostream>

using namespace std;

 //当段数和数目总长度极大且当前切割长度较小时，切割段数可能极大
typedef long long ll;

const int N = 1e5 + 10;

ll n, k, a[N];

//计算没跟木头按照当前切割长度可以切割多少段，累加在cnt上
ll calc(ll x)
{
    ll cnt = 0;
    for(int i = 1; i <= n; i ++)
    {
        cnt += a[i] / x;
    }

    return cnt;
}

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }

    ll l = 1, r = 1e8;
    
    //求可行解的右端，即最大可行解
    while(l < r)
    {
        ll mid = (l + r + 1) / 2;
        if(calc(mid) >= k) l = mid;
        else r = mid - 1;
    }

    cout << l << endl;

    return 0;
}

