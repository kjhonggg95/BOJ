#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using pii = pair<int,int>;

#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int maze[105][105];
int dist[105][105];
bool vis[105][105];

queue<pii> q;

int main()
{
	fastio;
	int n, m;
    cin >> n >> m;
    for(int i = 0;i<n;i++)
    {
        string str;
        cin >> str;
        for(int j = 0;j<str.length();j++)
            maze[i][j] = str[j] - '0';
    }

    q.push({0,0});
    vis[0][0] = true;

    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for(int dir = 0; dir<4;dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(maze[nx][ny] == 0 || vis[nx][ny]) continue;

            q.push({nx,ny});
            vis[nx][ny] = true;

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        }
    }

    cout << dist[n-1][m-1] + 1;

	return 0;
}
