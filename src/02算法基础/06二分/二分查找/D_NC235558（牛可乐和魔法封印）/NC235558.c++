#include <iostream>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

ll a[N];
int n, q;

int binary_search(ll x, ll y)
{
    //循环找区间左边界x
    int l = 1, r = n, mid = 0;
    while(l < r)
    {
        mid = (l + r) / 2;
        if(a[mid] >= x) r = mid;
        else l = mid + 1;
    }
    if(a[l] < x) return 0; //循环结束也不存在>=x的
    int t = l;
    
    //循环找区间右边界y
    l = 1, r = n, mid = 0;
    while(l < r)
    {
        mid = (l + r + 1) / 2;
        if(a[mid] <= y) l = mid;
        else r = mid - 1;
    }
    if(a[l] > y) return 0; //循环结束也不存在<=x的
    
    return l - t + 1;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }
    
    cin >> q;
    ll x, y;
    while(q --)
    {
        cin >> x >> y;
        cout << binary_search(x, y) << endl;
    }
    return 0;
}