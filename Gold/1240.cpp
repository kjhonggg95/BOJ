#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using pii = pair<int, int>;

#define X first
#define Y second

vector<vector<pii>> node;
bool vis[1005];

int bfs(int st, int en)
{
    queue <pii> q;
    q.push({st, 0});
    vis[st] = true;

    while (!q.empty())
    {
        int now = q.front().X;
        int cost = q.front().Y;
        q.pop();

        if (now == en)
        {
            return cost;
        }

        for (auto e : node[now])
        {
            if (vis[e.X]) continue;
            q.push({e.X, cost + e.Y});
            vis[e.X] = true;
        }
    }
}

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    node.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, dist;
        cin >> u >> v >> dist;
        node[u].push_back({v, dist});
        node[v].push_back({u, dist});
    }

    for (int i = 0; i < m; i++)
    {
        memset(vis, 0, sizeof(vis));
        int st, en;
        cin >> st >> en;

        cout << bfs(st, en) << '\n';
    }
}