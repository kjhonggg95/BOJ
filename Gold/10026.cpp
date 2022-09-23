#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using pii = pair<int,int>;

#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

char pic[105][105];
bool vis[105][105];

int n, cnt1, cnt2;

queue<pii> q;

int bfs()
{
    int cnt = 0;

    for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++)
            {
                if(vis[i][j]) continue;
                q.push({i,j});
                cnt++;

                while(!q.empty())
                {
                    auto cur = q.front();
                    q.pop();

                    for(int dir = 0;dir<4;dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if(nx < 0 || nx >=n || ny<0 || ny>=n) continue;
                        if(vis[nx][ny] ||  (pic[nx][ny] != pic[cur.X][cur.Y])) continue;

                        q.push({nx,ny});
                        vis[nx][ny] = true;
                    }
                }
            }

    return cnt;
}

int main()
{
    cin >> n;
    for(int i = 0;i<n;i++)
    {
        string str;
        cin >> str;
        for(int j = 0;j<n;j++)
            pic[i][j] = str[j];
    }

    cnt1 = bfs();

    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            if(pic[i][j] == 'R')
                pic[i][j] = 'G';

    memset(vis, 0, sizeof(vis));

    cnt2 = bfs();
    
    cout << cnt1 << ' ' << cnt2;
}