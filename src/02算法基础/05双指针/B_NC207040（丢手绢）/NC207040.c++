#include <iostream>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n; //小朋友的数量
ll a[N];

int main()
{
    cin >> n;
    ll sum = 0; //圆环周长L
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        sum += a[i];
    }

    int left = 1, right = 1;
    ll k = 0, res = 0; //其中k为弧长总和

    while(right <= n)
    {
        k += a[right];
        while(2 * k >= sum)
        {
            //当符合条件时，res为圆环长减去总弧长（此时一定为劣弧）与原来res的最小值
            res = max(res, sum - k);
            k -= a[left ++];
        }

        //当前窗口k为小于sum / 2的合法程度，使用新k更新res
        res = max(res, k); //与上一个max形成判断优劣弧
        right ++;
    }

    cout << res << endl;

    return 0;
}