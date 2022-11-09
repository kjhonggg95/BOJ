#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 1001;

int A[MAX], B[MAX];
bool vis[MAX];

vector<int> adj[MAX];

bool dfs(int a)
{
    vis[a] = true;
    for (int b : adj[a])
    {
        if (B[b] == -1 || (!vis[B[b]] && dfs(B[b])))
        {
            A[a] = b;
            B[b] = a;
            return true;
        }
    }

    return false;
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        memset(A, -1, sizeof(A));
        memset(B, -1, sizeof(B));
        memset(vis, false, sizeof(vis));


        for(int i = 0;i<MAX;i++)
            adj[i].clear();

        int n, m;
        cin >> n >> m;

        for(int i = 1;i<=m;i++)
        {
            int a, b;
            cin >> a >> b;

            for(int j = a;j<=b;j++)
                adj[i].push_back(j);
        }

        int match = 0;
       
        for (int i = 1; i <= m; i++)
        {
            if (A[i] == -1) // 아직 매칭되지 않음
            {
                memset(vis, false, sizeof(vis));
                if (dfs(i))
                    match++;
            }
        }

        cout << match << '\n';
    }
}