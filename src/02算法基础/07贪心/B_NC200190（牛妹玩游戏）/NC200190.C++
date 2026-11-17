//本题无法使用贪心，需要使用状态压缩，因为不符合贪心选择性

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 20;
int a[N][N];
int col[N]; // 统计每一列剩余的和

// 统计 x 的二进制里面 1 的个数（手写版本，等价 __builtin_popcount）
int calc(int x)
{
    int ret = 0;
    while(x)
    {
        ret++;
        x -= x & -x;
    }
    return ret;
}

// 排序比较函数：从大到小
bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    int ret = 0;
    // st 是二进制mask，枚举所有选行的方案
    for(int st = 0; st < (1 << n); st++)
    {
        int cnt = calc(st); // 这个方案一共选了多少行
        if(cnt > k) continue; // 选的行数超过k，直接跳过

        memset(col, 0, sizeof(col));
        int sum = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if((st >> i) & 1)
                {
                    // 这一行被选中，值加到总分
                    sum += a[i][j];
                }
                else
                {
                    // 这一行没被选，累加进这一列的剩余价值（后面可以选列拿）
                    col[j] += a[i][j];
                }
            }
        }

        // 列从大到小排序
        sort(col, col + m, cmp);
        // 剩下名额：k - cnt 个，挑最大的几列加上
        for(int i = 0; i < k - cnt; i++)
        {
            sum += col[i];
        }
        ret = max(ret, sum);
    }

    cout << ret << endl;
    return 0;
}
