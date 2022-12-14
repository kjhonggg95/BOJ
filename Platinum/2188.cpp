#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 201;

int A[MAX], B[MAX];
bool vis[MAX];

vector<int> adj[MAX];

bool dfs(int a)
{
    vis[a] = true;
    for(int b : adj[a])
    {
        // a - b 매칭이 안되어있거나 || 매칭되어있던 정점을 다른 정점과 매칭시킬 수 있으면 true
        if(B[b] == -1 || (!vis[B[b]] && dfs(B[b])))
        {
            A[a] = b;
            B[b] = a;
            return true;
        }
    }

    // 매칭 실패
    return false;
}

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++)
    {
        int nWork; cin >> nWork;
        
        for(int j = 0;j<nWork;j++)
        {
            int x; cin >> x;
            adj[i].push_back(x);
        }
    }

    int match = 0;
    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));

    for(int i = 1;i<=n;i++)
    {
        if(A[i] == -1) // 아직 매칭되지 않음
        {
            memset(vis, false, sizeof(vis));
            if(dfs(i)) match++;
        }
    }

    cout << match;
}