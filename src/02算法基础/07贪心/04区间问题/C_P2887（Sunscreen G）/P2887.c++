#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2510;

int C, L, res;

//牛
struct node1
{
    int l, r; //最小值和最大值
}a[N];

//防晒霜
struct node2
{
    int spf, sum; //防晒值和数量
}b[N];

//两个cmp都是升序排列
bool cmp1(node1& x, node1& y)
{
    return x.r < y.r;
}

bool cmp2(node2& x, node2& y)
{
    return x.spf < y.spf;
}

int main()
{
    cin >> C >> L;
    for(int i = 1; i <= C; i ++)
    {
        cin >> a[i].l >> a[i].r;
    }
    for(int i = 1; i <= L; i ++)
    {
        cin >> b[i].spf >> b[i].sum;
    }

    sort(a + 1, a + C + 1, cmp1);
    sort(b + 1, b + L + 1, cmp2);

    for(int i = 1; i <= C; i ++) //遍历每个牛
    {
        int j = 1; //每一头新奶牛，j回到开头（指针回退）
      
        while(j <= L)
        {
            if(b[j].spf < a[i].l) j ++; //防晒霜太小，换下一个（当前防晒霜可能被其他牛使用，故每次从j = 1开始循环)
            else if(b[j].spf > a[i].r) break; //防晒霜太大，因为升序排列，后续全都更大，故直接退出
            else
            {
                //落在区间内
                if(b[j].sum > 0)
                {
                    res ++; //结果 ++
                    b[j].sum --;//防晒霜数目减少
                    break; //后续不用判定了
                }
                else j ++; //该防晒霜用完了，找下一个
            }
        }
    }

    cout << res << endl;
    
    return 0;
}