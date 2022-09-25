#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using pii = pair<int,int>;

#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int r, c, cnt, maxcnt;
char board[25][25];
bool vis[25][25];
bool used[26]; // A~Z

queue<pii> q;

void dfs(int x, int y, int cnt)
{
    maxcnt = max(cnt, maxcnt);

    for(int dir = 0;dir<4;dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx < 0 || nx >=r || ny < 0 || ny >= c) continue;
        if(vis[nx][ny] || used[board[nx][ny] - 'A']) continue;

        vis[nx][ny] = true;
        used[board[nx][ny] - 'A'] = true;

        dfs(nx,ny, cnt + 1);

        vis[nx][ny] = false;
        used[board[nx][ny] - 'A'] = false;
    }
}

int main()
{
    fastio;
    cin >> r >> c;
    for(int i = 0;i<r;i++)
    {
        string str;
        cin >> str;
        for(int j = 0;j<c;j++)
            board[i][j] = str[j];
    }

    q.push({0,0});
    vis[0][0] = true;
    used[board[0][0] - 'A'] = true;
    cnt = 1;

    dfs(0, 0, cnt);

    cout << maxcnt;
}