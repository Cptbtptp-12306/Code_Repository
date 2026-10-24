#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 5e3 + 10;
int n, m;
int f[N][N];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;
    memset(f, 0, sizeof(f));

    int x, y, v;
    for(int i = 1; i <= n; i ++)
    {
        cin >> x >> y >> v;
        //因为可能有重复的位置，故+=v
        f[++ x][++ y] += v; //直接使用f数组存值，由于是从0开始的，++x变成从1开始，方便操作
    }

    //可能存在位置为5000的点，故循环写到5001
    for(int i = 1; i <= 5001; ++i)
    {
        for(int j = 1; j <= 5001; ++j)
        {
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j-1] + f[i][j];
        }
    }

    int res = 0;
    for(int i = m; i <= 5001; i ++)
    {
        for(int j = m; j <= 5001; j ++)
        {
            //获取当前res和以i，j为右下顶点且变长为m的区域的价值的最大值
            res = max(res, f[i][j] - f[i - m][j] - f[i][j - m] + f[i - m][j - m]);
        }
    }

    cout << res << endl;
    return 0;
}