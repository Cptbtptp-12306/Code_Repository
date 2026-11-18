#include <iostream>

using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

int n;
ll res = -1e6; //可能会出现全负数的情况，此时如果初始值为0，该情况仍会出现错误的0解

int main()
{
    cin >> n;
    ll t = 0;
    while(n --)
    {
        int x; cin >> x;
        t += x; //临时值变化
        res = max(res, t); //选择当前临时值和全局最优值之间的最大值
        if(t < 0) t = 0; //当前面的区间和<0时，贡献为负，故直接舍去并置t为0
    }
    cout << res << endl;
    return 0;
}