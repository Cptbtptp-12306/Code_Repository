#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n;
struct node
{
    int t;
    int d;
}a[N];

//吃草多的优先处理，乘积大的在左侧
bool cmp(node& x, node& y)
{
    return x.t * y.d < y.t * x.d;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i].t >> a[i].d;
    }

    sort(a + 1, a + n + 1, cmp); //排序

    //接哪头牛那头就停止吃草，其余牛继续吃草
    ll res = 0, t = 0;
    for(int i = 1; i <= n; i ++)
    {
        res += a[i].d * t; //初始时间为0
        t += 2 * a[i].t; //2T加入总时间，这是下一头牛吃草的时间
    }

    cout << res << endl;

    return 0;
}