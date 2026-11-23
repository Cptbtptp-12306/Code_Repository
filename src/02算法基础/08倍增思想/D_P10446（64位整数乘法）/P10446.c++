#include <iostream>

using namespace std;

typedef long long ll;

ll qmul(ll a, ll b, ll p)
{
    ll res = 0;
    while(b)
    {
        if(b & 1) res = (res + a) % p; //若b的二进制最低位为1，把当前的a加入答案并取模
        a = (a + a) % p; //a倍增
        b >>= 1; //提取b的二进制位
    }
    return res;
}

int main()
{
    ll a, b, p;
    cin >> a >> b >> p;
    cout << qmul(a, b, p) << endl;
    
    return 0;
}
