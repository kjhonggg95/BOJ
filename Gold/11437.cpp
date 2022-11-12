#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

const int sz = 50001;
const int MAX = 20;

int n, m;

vector<int> g[sz];
int depth[sz];
int dp[sz][MAX];
bool vis[sz];

void makeTree(int cur, int d)
{
    vis[cur] = true;
    depth[cur] = d;

    for(auto nxt : g[cur])
    {
        if(vis[nxt]) continue;
        dp[nxt][0] = cur;
        makeTree(nxt, d + 1);
    }
}

void makeTable()
{
    for(int j = 1;j<MAX;j++)
        for(int i = 1;i<=n;i++)
            dp[i][j] = dp[dp[i][j-1]][j-1];
}

int main()
{
    fastio;
    
    cin >> n;

    for(int i = 0;i<n-1;i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    makeTree(1,0);
    makeTable();

    cin >> m;
    while(m--)
    {
        int u, v;
        cin >> u >> v;

        if(depth[u] < depth[v]) swap(u,v);

        int diff = depth[u] - depth[v];

        for(int j =0;diff;j++)
        {
            if(diff & 1) u = dp[u][j];
            diff >>= 1;
        }

        if(u == v)
            cout << u << '\n';
        else
        {
            for(int j = MAX - 1;j>=0;j--)
                if(dp[u][j] != dp[v][j])
                {
                    u = dp[u][j];
                    v = dp[v][j];
                }
            cout << dp[u][0] << '\n';
        }
    }
}