#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using pii = pair<int, int>;

#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool vis[1005][1005];
int farm[1005][1005];

int main()
{
    fastio;
    int n;
    queue<pii> q;
    cin >> n;

    for(int i = 0;i<n;i++)
    {
        string str;
        cin >> str;
        for(int j = 0;j<n;j++)
        {
            if(str[j] == '.')
                farm[i][j] = 0;
            else
                farm[i][j] = 1;
        }
    }

    int cnt = 0;

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(farm[i][j] == 0 || vis[i][j]) continue;
            q.push({i,j});
            vis[i][j] = true;
            cnt++;

            while(!q.empty())
            {
                auto cur = q.front();
                q.pop();

                for(int dir = 0;dir<4;dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(farm[nx][ny] == 0 || vis[nx][ny]) continue;

                    q.push({nx,ny});
                    vis[nx][ny] = true;
                }
            }
        }
    }

    cout << cnt;
}