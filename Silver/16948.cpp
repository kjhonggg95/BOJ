#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using pii = pair<int,int>;

#define X first
#define Y second

int board[205][205];
bool vis[205][205];

int main()
{
    fastio;
    int n, r1,r2,c1,c2;
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;
    
    queue<pair<pii,int>> q;
    q.push({{r1,c1}, 0});
    vis[r1][c1] = true;

    while(!q.empty())
    {
        auto cur = q.front().X;
        int cnt = q.front().Y;
        q.pop();

        if(cur.X == r2 && cur.Y == c2)
        {
            cout << cnt;
            return 0;
        }

        if(cur.X - 2 >= 0 && cur.Y - 1 >= 0 && !vis[cur.X-2][cur.Y-1])
        {
            vis[cur.X-2][cur.Y-1] = true;
            q.push({{cur.X-2,cur.Y-1}, cnt + 1});
        }
        if(cur.X - 2 >= 0 && cur.Y + 1 < n && !vis[cur.X-2][cur.Y+1])
        {
            vis[cur.X-2][cur.Y+1] = true;
            q.push({{cur.X-2,cur.Y+1}, cnt + 1});
        }
        if(cur.Y - 2 >= 0 && !vis[cur.X][cur.Y-2])
        {
            vis[cur.X][cur.Y-2] = true;
            q.push({{cur.X,cur.Y-2}, cnt + 1});
        }
        if(cur.Y + 2 < n && !vis[cur.X][cur.Y+2])
        {
            vis[cur.X][cur.Y+2] = true;
            q.push({{cur.X,cur.Y+2}, cnt + 1});
        }
        if(cur.X + 2 < n && cur.Y - 1 >= 0 && !vis[cur.X+2][cur.Y-1])
        {
            vis[cur.X+2][cur.Y-1] = true;
            q.push({{cur.X+2,cur.Y-1}, cnt + 1});
        }
        if(cur.X + 2 < n && cur.Y + 1 < n && !vis[cur.X+2][cur.Y+1])
        {
            vis[cur.X+2][cur.Y+1] = true;
            q.push({{cur.X+2,cur.Y+1}, cnt + 1});
        }
    }

    cout << "-1";
    return 0;
}