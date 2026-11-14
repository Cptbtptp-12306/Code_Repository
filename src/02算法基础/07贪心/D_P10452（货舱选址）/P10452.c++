#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n, a[N];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    ll res = 0;
    //利⽤中间值来计算
    //for(int i = 1; i <= n; i++)
    //{
    //    ret += abs(a[i] - a[n / 2]);
    //}
    
    //⽤结论计算
    for(int i = 1; i <= n / 2; i ++)
    {
        //abs(a[i] - mid) + abs(a[n - i + 1] - mid)的结果，mid抵消，刚好为倒数i项-正数i项
        res += a[n - i + 1] - a[i];
    }

    cout << res << endl;
    
    return 0;
}