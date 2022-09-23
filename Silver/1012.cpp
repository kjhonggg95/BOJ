#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using pii = pair<int,int>;

#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int farm[55][55];
bool vis[55][55];

int main()
{
    fastio;
    int t;
    cin >> t;
    while(t--)
    {
        memset(farm,0,sizeof(farm));
        memset(vis,0,sizeof(vis));
        queue<pii> q;
        int m,n,k, worm = 0;
        cin >> m >> n >> k;
        for(int i = 0;i<k;i++)
        {
            int x, y;
            cin >> y >> x;
            farm[x][y] = 1;
        }

        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(farm[i][j] == 0 || vis[i][j]) continue;
                q.push({i,j});
                vis[i][j] = true;
                worm++;

                while(!q.empty())
                {
                    auto cur = q.front();
                    q.pop();

                    for(int dir = 0; dir<4;dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if(nx < 0 || nx >=n || ny < 0 || ny >=m) continue;
                        if(farm[nx][ny] == 0 || vis[nx][ny]) continue;

                        q.push({nx,ny});
                        vis[nx][ny] = true;
                    }
                }
            }
        }
        cout << worm << '\n';
    }
}