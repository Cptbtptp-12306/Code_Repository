#include <iostream>

using namespace std;

typedef long long ll;

const int N = 5e5 + 10;

int L, m, n;
ll a[N]; //石头到起点的距离

//对于当前x，若拿走c个石头使每个石头间距>=x时，c与m是否符合要求
ll check(int x)
{
    ll res = 0;
    int i = 0; //上一块保留石头
    while(i <= n)
    {
        int j = i + 1; //下一个个石头和石头i
        //固定i，移动j
        while(j <= n && a[j] - a[i] < x) //j不到n且两块石头的距离小于x，因为要求两个石头至少间距要大于等于x
        {
            j++;
        }
        res += j - i - 1; //不包括石头j
        i = j; //直接跳到下一个保留点，没有减1
    }

    return res;
}

int main()
{
    cin >> L >> n >> m;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }
    a[n + 1] = L;
    n ++;

    ll l = 1, r = L;
    while(l < r)
    {
        ll mid = (l + r + 1) / 2;
        if(check(mid) <= m) l = mid;
        else r = mid - 1;
    }

    cout << l << endl;

    return 0;
}