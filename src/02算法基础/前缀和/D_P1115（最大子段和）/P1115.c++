#include <iostream>

using namespace std;

const int N = 2e5 + 10;

int a[N], f[N];
int n;

//相当于维护两个区间[0, L]和[0, R]，若要[L, R]最大，则要让[0, R]尽可能大，[0, L}尽可能小
//本质为双循环，优化思路为使用历史变量消去内循环，使O(n ^ 2) -> O(n)
int main()
{
    f[0] = 0;
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        f[i] = f[i - 1] + a[i]; //常规前缀和
    }

    int res = -2e5; //相当于负无穷
    int MIN = 0;

    for(int i = 1; i <= n; i ++)
    {
        res = max(res, f[i] - MIN); //比获取es和当前区间的最大值
        MIN = min(MIN, f[i]); //获取当前MIN和后续区间和的最小值，中间不会让MIN更小的直接跳过
    }

    cout << res << endl;
    
    return 0;
}