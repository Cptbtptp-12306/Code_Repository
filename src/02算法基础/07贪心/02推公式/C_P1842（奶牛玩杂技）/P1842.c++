#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 5e4 + 10;

int n;
//创建结构体
struct node
{
    int w;
    ll s;
}a[N];

//比较函数，交换得W + x.w - y.s < W + y.w - x.s，即压扁指数小的排在左侧（上面）
bool cmp(node& x, node& y)
{
    return x.w + x.s < y.w + y.s;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i].w >> a[i].s;
    }
    sort(a + 1, a + n + 1, cmp);

    ll res = -1e9, w = 0; //res为压扁指数，可能为负数，所以初始值不能为0
    for(int i = 1; i <= n; i ++)
    {
        res = max(res, w - a[i].s); //比较历史res和当前第i头牛的压扁指数
        w += a[i].w; //初始w为0，因为第一头年上面没有其他牛，其余需要把上一头牛体重加进去
    }

    cout << res << endl;
    
    return 0;
}