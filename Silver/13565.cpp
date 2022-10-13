#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using pii = pair<int,int>;

#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int arr[1001][1001];
bool vis[1001][1001];

int main()
{
    fastio;
    int r, c;
    cin >> r >> c;
    for(int i = 0;i<r;i++)
    {
        string s;
        cin >> s;
        for(int j = 0;j<c;j++)
            arr[i][j] = s[j] - '0';
    }

    queue<pii> q;
    for(int i = 0;i<c;i++)
        if(arr[0][i] == 0)
        {
            q.push({0,i});
            vis[0][i] = true;
        }

    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for(int dir = 0;dir<4;dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= r || ny < 0 || ny >=c) continue;
            if(vis[nx][ny] || arr[nx][ny] == 1) continue;

            vis[nx][ny] = true;
            arr[nx][ny] = arr[cur.X][cur.Y] + 2;
            q.push({nx,ny});
        }
    }
    for(int i = 0;i<c;i++)
    {
        if(arr[r-1][i] > 1)
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}