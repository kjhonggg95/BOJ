#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 101;

int A[MAX], B[MAX];
vector<int> adj[MAX];

bool vis[MAX];

bool dfs(int a)
{
    vis[a] = true;
    for (auto b : adj[a])
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

struct shark
{
    int a;
    int b;
    int c;
};

int main()
{
    fastio;
    int n;
    cin >> n;
    vector<shark> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[i] = {a,b,c};
    }

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if(v[i].a == v[j].a && v[i].b == v[j].b && v[i].c == v[j].c)
            {
                adj[i * 2 - 1].push_back(j);
                adj[i * 2].push_back(j);
            }
            else if (v[i].a >= v[j].a && v[i].b >= v[j].b && v[i].c >= v[j].c)
            {
                adj[i * 2 - 1].push_back(j);
                adj[i * 2].push_back(j);
            }
            else if (v[i].a <= v[j].a && v[i].b <= v[j].b && v[i].c <= v[j].c)
            {
                adj[j * 2 - 1].push_back(i);
                adj[j * 2].push_back(i);
            }
        }
    }

    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));

    int match = 0;

    for (int i = 1; i <= n * 2; i++)
    {
        if (A[i] == -1)
        {
            memset(vis, false, sizeof(vis));
            if (dfs(i))
                match++;
        }
    }

    cout << max(n - match, 1);
}