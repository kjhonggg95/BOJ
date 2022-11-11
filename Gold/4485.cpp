#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

using pii = pair<int, int>;

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

const int MAX = 1e8;
int cave[126][126];
int dist[126][126];

int main()
{
    int tc = 1;
    while (1)
    {
        memset(cave, 0, sizeof(cave));
        int n;
        cin >> n;
        if (n == 0)
            return 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> cave[i][j];
                dist[i][j] = MAX;
            }
        dist[0][0] = cave[0][0];
        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;

        pq.push({cave[0][0], {0, 0}});

        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            if (dist[cur.Y.X][cur.Y.Y] != cur.X)
                continue;

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.Y.X + dx[dir];
                int ny = cur.Y.Y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;
                if (dist[nx][ny] <= dist[cur.Y.X][cur.Y.Y] + cave[nx][ny])
                    continue;
                dist[nx][ny] = dist[cur.Y.X][cur.Y.Y] + cave[nx][ny];
                pq.push({dist[nx][ny], {nx, ny}});
            }
        }

        cout << "Problem " << tc++ << ": " << dist[n - 1][n - 1] << '\n';
    }
}