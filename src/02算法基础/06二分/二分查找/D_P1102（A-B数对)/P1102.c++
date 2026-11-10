#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

int n;
ll a[N], c;

int main()
{
    cin >> n >> c;

    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1); //构造递增序列

    ll res = 0; //由于极端情况，可能出现4e10级别的数据量：2e5 ^ 2
    for(int i = 2; i <= n; i ++)
    {
        ll b = a[i] - c; //A - B = C，则B = A - C，枚举全部A，二分查找B即可
        //STL，迭代器返回数组下标，求出的值就是对应b的数目（如果b存在且可能b有多个）
        res += upper_bound(a + 1, a + i + 1, b) - lower_bound(a + 1, a + i + 1, b);
    }

    cout << res << endl;

    return 0;
}