#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

using pii = pair<int, int>;

#define X first
#define Y second

const int MAX = 20;
const int SZ = 40001;

int n, m;

vector<pii> g[SZ];
int dist[SZ]; // 1 ~ n번 정점까지 가는 비용
int depth[SZ];
int dp[SZ][MAX];
int vis[SZ];

void makeTree(int cur, int d, int c)
{
    vis[cur] = true;
    depth[cur] = d;
    dist[cur] = c;

    for (auto nxt : g[cur])
    {
        if (vis[nxt.X])
            continue;
        dp[nxt.X][0] = cur;
        makeTree(nxt.X, d + 1, c + nxt.Y);
    }
}

void makeTable()
{
    for (int j = 1; j < MAX; j++)
        for (int i = 1; i <= n; i++)
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
}

int main()
{
    fastio;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    makeTree(1, 0, 0);
    makeTable();

    cin >> m;
    while (m--)
    {
        int u, v, lca;
        cin >> u >> v;

        int du = dist[u];
        int dv = dist[v];

        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int j = 0; diff; j++)
        {
            if (diff & 1)
                u = dp[u][j];
            diff >>= 1;
        }

        if (u == v)
            lca = u;
        else
        {
            for (int j = MAX - 1; j >= 0; j--)
                if (dp[u][j] != dp[v][j])
                {
                    u = dp[u][j];
                    v = dp[v][j];
                }
            lca = dp[u][0];
        }

        cout << du + dv - 2 * dist[lca] << '\n';
    }
}