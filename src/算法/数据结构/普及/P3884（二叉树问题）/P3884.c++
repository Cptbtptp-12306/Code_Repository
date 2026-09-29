#include <iostream>
#include <vector>

using namespace std;

const int N = 110;
int n, u, v;
vector<int> edges[N]; //单向边
int fa[N]; //存父节点
int dist[N]; //路径距离

//递归计算深度
int dfs(int u)
{
    int res = 0;
    for(auto v : edges[u])
    {
        res = max(res, dfs(v));
    }
    
    return res + 1;
}

//递归计算宽度（队列）
int bfs()
{
    queue<int> q;

    q.push(1);
    int res = 0;

    //如果队列中有数据，循环处理
    while(q.size())
    {
        int sz = q.size(); //找到当前队列长度（即数据的数量）
        res = max(res, sz);

        //处理队列里每个数据
        while(sz --)
        {
            int u = q.front(); //临时变量u为q的头节点
            q.pop(); //弹出头节点

            //便利当前队列每个数据的子节点
            for(auto v : edges[u])
            {
                q.push(v);
            }
        }
    }
    return res;
}

int main()
{
    cin >> n;

    //仅存单向边，父节点单独存储
    for(int i = 0; i < n - 1; i ++)
    {
        cin >> u >> v;
        edges[u].push_back(v);
        fa[v] = u;
    }

    cout << dfs(1) << endl;
    cout << bfs() << endl;

    //找到最近的公共祖先
    int x, y;
    cin >> x >> y;
    while(x != 1)
    {
        dist[fa[x]] = dist[x] + 1;
        x = fa[x];
    }

    int len = 0;
    while(y != 1 && dist[y] == 0)
    {
        len ++;
        y = fa[y];
    }

    cout << dist[y] * 2 + len << endl;
    return 0;
}