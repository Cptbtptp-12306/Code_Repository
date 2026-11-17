#include <iostream>
#include <algorithm>

using namespace std;

const int N = 3e4 + 10;

int n, w, a[N];

int main()
{
    cin >> w >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1); //排序小到大

    int l = 1, r = n, res = 0;

    //两两一组，一定是大+小，注意是否整体超过w
    while(l <= r) //若l < r，则会出现l = r的这一项无法进入循环
    {
        if(a[l] + a[r] <= w) //未超过w，直接分在一组
        {
            l ++;
            r --;
        }
        else r --; //超过w，大价值的单独一组

        res ++;
    }
    cout << res << endl;
    return 0;
}