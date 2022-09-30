#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using pii = pair<int, int>;

#define X first
#define Y second

vector<vector<int>> v;
int minval = 1e9, minidx;
bool vis[105];

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    // 중복 제거
    for (int i = 0; i < n; i++)
    {
        sort(v[i].begin(), v[i].end());
        v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
    }

    for (int i = 0; i < n; i++)
    {
        queue<pii> q;
        int sum = 0;
        memset(vis, 0, sizeof(vis));
        vis[i] = true;

        for (int j = 0; j < v[i].size(); j++)
        {
            q.push({ v[i][j], 1 });
            vis[v[i][j]] = true;
        }

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            int idx = cur.X;
            int cnt = cur.Y;
            sum += cnt;

            for (int k = 0; k < v[idx].size(); k++)
            {
                if (vis[v[idx][k]]) continue;

                q.push({ v[idx][k], cnt + 1 });
                vis[v[idx][k]] = true;
            }
        }

        if (sum < minval)
        {
            minval = sum;
            minidx = i;
        }
        else if (sum == minval)
        {
            if (i < minidx)
                minidx = i;
        }
    }

    cout << minidx + 1;
}