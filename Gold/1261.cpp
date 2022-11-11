#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

using pii = pair<int,int>;

#define X first
#define Y second

const int MAX = 1e9;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int maze[101][101];
int dist[101][101];

int main()
{
    fastio;
    int n, m;
    cin >> m >> n;

    for(int i = 0;i<n;i++)
    {
        string s; cin >> s;
        for(int j = 0;j<m;j++)
        {
            maze[i][j] = s[j] - '0';
            dist[i][j] = 1e9;
        }
    }
    dist[0][0] = 0;

    priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> pq;
    pq.push({dist[0][0], {0,0}});
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if(dist[cur.Y.X][cur.Y.Y] != cur.X) continue;

        for(int dir = 0; dir < 4; dir++)
        {
            int nx = cur.Y.X + dx[dir];
            int ny = cur.Y.Y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] <= dist[cur.Y.X][cur.Y.Y] + maze[nx][ny]) continue;
            dist[nx][ny] = dist[cur.Y.X][cur.Y.Y] + maze[nx][ny];
            pq.push({dist[nx][ny], {nx,ny}});
        }
    }

    cout << dist[n-1][m-1];
}