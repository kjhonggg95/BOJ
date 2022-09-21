#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using pii = pair<int,int>;

#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int store[1005][1005];
int days[1005][1005];

queue<pii> q;

int main()
{
	fastio;
	int n, m;
    cin >> m >> n;

    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
        {
            cin >> store[i][j];
            if(store[i][j] == 1)
                q.push({i,j});
            if(store[i][j] == 0)
                days[i][j] = -1;
        }


       while(!q.empty())
        {
            auto cur = q.front();
            q.pop();

            for(int dir = 0;dir<4;dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(days[nx][ny] >= 0) continue; // 맵에서 0인 부분만 탐색

                q.push({nx,ny});
                days[nx][ny] = days[cur.X][cur.Y] + 1;
            }
        }

    int maxday = 0;

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            // 토마토가 다 익지 못하는 상황
            if(days[i][j] == -1)
            {
                cout << -1;
                return 0;
            }
            maxday = max(days[i][j], maxday);
        }
    }

    cout << maxday;

	return 0;
}
