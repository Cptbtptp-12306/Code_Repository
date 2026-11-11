#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int m, n, a[N];

//先对分数线排序，符合条件的位置一定是pos和pos - 1，二分查找第一个pos即可
int main()
{
    cin >> m >> n;
    for(int i = 1; i <= m; i ++)
    {
        cin >> a[i];
    }

    sort(a + 1, a + m + 1);
    a[0] = -2e6; //左哨兵，a[1] - a[0]的值一定较大，min时一定取不到

    ll res = 0;
    for(int i = 1; i <= n; i ++)
    {
        int l = 1, r = m, mid = 0;
        int x; cin >> x;
        while(l < r)
        {
            mid = (l + r) / 2;
            if(a[mid] >= x) r = mid;
            else l = mid + 1;
        }
        res += min(abs(a[l] - x), abs(a[l - 1] - x)); //计算最小的绝对值
    }

    cout << res << endl;
    
    return 0;
}