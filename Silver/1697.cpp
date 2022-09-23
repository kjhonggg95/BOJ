#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using pii = pair<int,int>;

#define X first
#define Y second

bool vis[100005];

int main()
{
    fastio;
    int n, k;
    queue<pii> q;
    cin >> n >> k;
    q.push({n,0});
    vis[n] = true;

    while(!q.empty())
    {
        int now = q.front().X;
        int cnt = q.front().Y;
        q.pop();

        if(now == k)
        {
            cout << cnt;
            return 0;
        }

        if(now - 1 >= 0 && !vis[now - 1])
        {
            q.push({now - 1, cnt + 1});
            vis[now-1] = true;
        }
        if(now + 1 <= 100000 && !vis[now + 1])
        {
            q.push({now + 1, cnt + 1});
            vis[now+1] = true;
        }
        if(now * 2 <=100000 && !vis[now * 2])
        { 
            q.push({now * 2, cnt + 1});
            vis[now*2] = true;
        }
         
    }
}