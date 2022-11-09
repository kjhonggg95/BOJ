#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 2001;

int A[MAX], B[MAX];
bool vis[MAX];

vector<int> adj[MAX];

// A  -   B
// 1  -  1 2 
// 2  -  1
// 3  -  2 3
// 4  -  3 4 5
// 5  -  1


bool dfs(int a)
{
    vis[a] = true;
    for(int b : adj[a])
    {
        // a - b ��Ī�� �ȵǾ��ְų� || ��Ī�Ǿ��ִ� ������ �ٸ� ������ ��Ī��ų �� ������ true
        if(B[b] == -1 || (!vis[B[b]] && dfs(B[b])))
        {
            A[a] = b;
            B[b] = a;
            return true;
        }
    }

    // ��Ī ����
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
            adj[i * 2 - 1].push_back(x);
            adj[i * 2].push_back(x);
        }
    }

    int match = 0;
    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));

    for(int i = 1;i<=n*2;i++)
    {
        if(A[i] == -1) // ���� ��Ī���� ����
        {
            memset(vis, false, sizeof(vis));
            if(dfs(i)) match++;
        }
    }

    cout << match;
}