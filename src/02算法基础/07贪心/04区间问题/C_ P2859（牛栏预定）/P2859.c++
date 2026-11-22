#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

const int N = 5e4 + 10;

int n;

struct node
{
    //记录开始时间，结束时间，排序前的位置，分配的牛棚号（因为这些不能被排序打乱）
    int x, y, pos, num; //pos可以根据原始数据输出答案
}a[N];

int cnt, res[N]; //记录牛棚数量和牛棚号（即答案）

//键为牛棚最后一头奶牛的结束时间，值为牛棚编号
//该数据结构内部自动从小到大排序，等价于小根堆，其键可以重复，因为牛棚可能有相同的结束时间（map的键不能重复）
multimap<int, int> st;

//按照开始时间升序排列
bool cmp(node& x, node& y)
{
    return x.x < y.x;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i].x >> a[i].y;
        a[i].pos = i; //保留原始位置
    }

    sort(a + 1, a + n + 1, cmp);

    for(int i = 1; i <= n; i ++)
    {
        int l = a[i].x, r = a[i].y;

        //寻找第一个键 > l的迭代器，即结束时间小于 l 的牛棚
        //multimap有序，lower_bound (l) 可以返回第一个严格大于 l 的迭代器
        auto it = st.lower_bound(l);
        
        if(it != st.begin()) //如果it不是容器开头，说明前面还有元素
        {
            -- it; //it往前挪一位 → 当前最大的 ed < l
            int p = it -> second; //p = 这个可用牛棚的编号
            st.erase(it); //把这个旧记录删掉：这个牛棚结束时间更新了
            st.insert({r, p}); //重新插入：这个牛棚现在结束时间变成 r，编号p不变
            a[i].num = p; //当前奶牛分配这个旧棚号p
        }
        else //it == begin()：不存在 ed < l 的牛棚，没有可用棚
        {
            st.insert({r, ++ cnt}); //新开棚：cnt先+1，插入新记录 {结束时间r，新棚号cnt}
            a[i].num = cnt; //当前奶牛分配新棚号cnt
        }
    }

    cout << cnt << endl;
    for(int i = 1; i <= n; i ++)
    {
        res[a[i].pos] = a[i].num; //ret[原始序号] = 棚号，把棚号放回数组，还原顺序
    }
    for(int i = 1; i <= n; i++) 
    {
        cout << res[i] << endl;
    }

    return 0;
}

