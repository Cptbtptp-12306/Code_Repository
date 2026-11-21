#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII; //存两个值

const int N = 1e6 + 10;

int n, res;
PII a[N];


int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        //反向存储，second存开始时间，first存结束时间，因为pair默认比较的根据first比较的
        cin >> a[i].second >> a[i].first; 
    }
    sort(a + 1, a + n + 1);

    int end = -1; //其实0也可以，但是更加严谨表示此时没有比赛
    for(int i = 1; i <= n; i ++)
    {
        if(a[i].second >= end) //如果第i场活动结束时间大于等于上一个参加活动结束时间（注意是参加的活动）
        {
            res ++; //活动数增加
            end = a[i].first; //end更新为最新参加的活动的结束时间
        }
    }

    cout << res << endl;
    
    return 0;
}