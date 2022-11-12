#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 18;

vector<int> g[100001];
int d[100001];
int dp[100001][MAX];
int vis[100001];

int n, m;

void makeTree(int cur, int depth)
{
    vis[cur] = true;
    d[cur] = depth;

    for (auto nxt : g[cur])
    {
        if (vis[nxt])
            continue;
        dp[nxt][0] = cur;
        makeTree(nxt, depth + 1);
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
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    makeTree(1, 0);
    makeTable();

    cin >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v; // 정점 u, v
        if (d[u] < d[v])
            swap(u, v); // 깊이 : u > v 로 만들기

        int diff = d[u] - d[v];

        // u를 v와 같은 깊이가 될 때 까지 조상으로 올리기
        for (int j = 0; diff; j++)
        {
            if (diff & 1)
                u = dp[u][j];
            diff >>= 1;
        }

        if (u == v)
            cout << u << '\n';
        else
        {
            for (int j = MAX - 1; j >= 0; j--)
                if (dp[u][j] != dp[v][j])
                {
                    u = dp[u][j];
                    v = dp[v][j];
                }

            cout <<  dp[u][0] << '\n';
        }
       
    }

}
