#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 1010;
const double eps = 1e-6; //容忍度

int n, d;
struct node
{
    double l, r;
}a[N];

//按照区间右端点排序
bool cmp(node& x, node& y)
{
    return x.r < y.r;
}

int main()
{
    int sum = 0; //记录当前是第几组测试用例

    while(cin >> n >> d, n && d)
    {
        sum ++;
        bool flag = false; //标记是否有覆盖不到的岛屿

        for(int i = 1; i <= n; i ++)
        {
            double x, y; cin >> x >> y;
            if(y > d) flag = true; //若雷达覆盖不到，标记为true
            else
            {
                double t = sqrt(d * d - y * y); //勾股定理计算岛屿到雷达的极限距离

                //计算当前岛屿的左右区间
                a[i].l = x - t;
                a[i].r = x + t;
            }
        }

        cout << "Case " << sum << ": ";

        if(flag) cout << -1 << endl;
        else
        {
            sort(a + 1, a + n +1, cmp);

            int res = 1; //初始化雷达数量为1
            double r = a[1].r; //记录第一个雷达的位置

            //从第二个岛屿遍历
            for(int i = 2; i <= n; i ++)
            {
                //若第i个岛屿左端点大于上一个记录雷达的岛屿的右端点，更新res和r（这个r为临时变量）
                if(a[i].l > r + eps) //可能出现2.0, 2.0 -> 1.9999999, 2.0000001这种情况
                {
                    res ++;
                    r = a[i].r;
                }
            }

            cout << res << endl;
        }
    }

    return 0;
}