#include <iostream>

using namespace std;

typedef long long ll;

const int N = 1e6 + 10;

int n, m, a[N];

//对于每个可行的h，计算树木高度 - 伐木机高度并求和，后续只要判断res与m的关系即可
ll check(int h)
{
    ll res = 0;
    for(int i = 1; i <= n; i ++)
    {
        if(a[i] > h) res += a[i] - h;
    }

    return res;
}

int main()
{
    cin >> n >> m;

    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }

    int l = 0, r = 4e5; //对答案二分，最小为0，最大为H_max
    //右端点模板，为找到最大的可行解
    while(l < r)
    {
        int mid = (l + r + 1) / 2;
        if(check(mid) >= m) l = mid;
        else r = mid - 1;
    }

    cout << l << endl;
    
    return 0;
}