#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int n, u, v;
vector<int> edges[N];
int fa[N];
int dist[N];

int dfs(int u)
{
    int res = 0;
    for(auto v : edges[u])
    {
        res = max(res, dfs(v));
    }
    return res + 1;
}

int bfs()
{
    queue<int> q;
    q.push(1);
    int res = 0;
    while(q.size())
    {
        int sz = q.size();
        res = max(res, sz);

        while(sz --)
        {
            int u = q.front();
            q.pop();
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
    for(int i = 0; i < n - 1; i ++)
    {
        cin >> u >> v;
        edges[u].push_back(v);
        fa[v] = u;
    }

    cout << dfs(1) << endl;
    cout << bfs() << endl;

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