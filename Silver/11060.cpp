#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using pii = pair<int,int>;

#define X first
#define Y second

int maze[1005];
bool vis[1005];

int main()
{
    fastio;
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++)
        cin >> maze[i];

    queue<pii> q;
    q.push({1,0});
    vis[1] = true;

    while(!q.empty())
    {
        int pos = q.front().X; // 0
        int cnt = q.front().Y;
        q.pop();
        
        if(pos == n)
        {
            cout << cnt;
            return 0;
        }

        // int i = 2; i<= 3
        for(int i = pos + 1;i<=pos + maze[pos];i++)
        {
            if(vis[i]) continue;
            q.push({i, cnt+1});
            vis[i] = true;
        }
        
    }

    cout << "-1";
}