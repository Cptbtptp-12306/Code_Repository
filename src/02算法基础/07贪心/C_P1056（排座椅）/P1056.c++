#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

struct node
{
    int index; //通道编号（用于最后输出）
    int cnt; //收益（该通道能切断多少对同学）
}row[N], col[N]; //横向和纵向通道数组

int m, n, k, l, d;

//按照cnt从大到小排序，即选择价值高的通道
bool cmp1(node& x, node& y)
{
    return x.cnt > y.cnt;
}

//按照index从小到大排序，即输出按编号升序排列
bool cmp2(node& x, node& y)
{
    return x.index < y.index;
}

int main()
{
    cin >> m >> n >> k >> l >> d;
    for(int i = 1; i <= m; i ++)
    {
        row[i].index = i;
    }
    for(int i = 1; i <= n; i ++)
    {
        col[i].index = i;
    }

    while(d --)
    {
        int x, y, p, q;
        cin >> x>> y >> p >> q;
        if(x == p) col[min(y, q)].cnt ++; //纵向通道
        else row[min(x, p)].cnt ++; //横向通道
    }

    //排序后按照价值降序排列（结构体使index一起移动，后续对index排序不会把价值排乱）
    sort(row + 1, row + m + 1, cmp1);
    sort(col + 1, col + n + 1, cmp1);

    //分别排序两个数组的前k, l个元素，按照index升序排列（注意不是全部重排，这等于前一个排序没有排）
    sort(row + 1, row + k + 1, cmp2);
    sort(col + 1, col + l + 1, cmp2);

    for(int i = 1; i <= k; i ++)
    {
        cout << row[i].index << " ";
    }
    cout << endl;
    for(int i = 1; i <= l; i ++)
    {
        cout << col[i].index << " ";
    }
    
    return 0;
}