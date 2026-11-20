#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

int n;
//priority_queue< 数据类型, 底层容器, 比较器 >
//priority_queue 默认是大根堆（即默认比较器是 less<ll>，堆顶是最大值）
priority_queue<ll, vector<ll>, greater<ll>> heap; //小根堆

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        ll x; cin >> x;
        heap.push(x);
    }

    ll len = 0;
    while(heap.size() > 1) //不能为0，因为最后一定还剩一棵树
    {
        //每次拿出最小的两棵树合并
        ll x = heap.top();
        heap.pop();
        ll y = heap.top();
        heap.pop();
        ll t = x + y;
        len += t;
        heap.push(t);
    }

    cout << len << endl;

    return 0;
}