#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using pii = pair<int,int>;

#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int paper[505][505];
bool vis[505][505];

int maxarea, pic;

queue<pii> q;

int main()
{
	fastio;
	int n, m;
    cin >> n >> m;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            cin >> paper[i][j];
    
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            int area = 0;
            if(vis[i][j] || paper[i][j] ==  0) continue;
            q.push({i,j});
            vis[i][j] = true;
            area++;
            pic++;

            while(!q.empty())
            {
                auto cur = q.front();
                q.pop();

                for(int dir = 0; dir<4;dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if(nx<0 || nx>=n || ny<0||ny>=m) continue;
                    if(vis[nx][ny]  || paper[nx][ny] == 0) continue;

                    q.push({nx,ny});
                    vis[nx][ny] = true;
                    area++;
                }
            }

            if(area > maxarea)
                maxarea = area;
        }
    }

    cout << pic << '\n' << maxarea;

	return 0;
}
