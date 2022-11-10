#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

using pii = pair<int, int>;

#define X first
#define Y second

vector<pii> adj[10001];
int dist[10001];

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        int n, d, c;
        cin >> n >> d >> c;

        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            dist[i] = INT_MAX;
        }

        for (int i = 0; i < d; i++)
        {
            int a, b, s;
            cin >> a >> b >> s;
            adj[b].push_back({s, a});
        }

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        dist[c] = 0;

        pq.push({dist[c], c});

        int maxtime = 0;
        int cnt = 0;

        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            if (dist[cur.Y] != cur.X)
                continue;
            for (auto nxt : adj[cur.Y])
            {
                if (dist[nxt.Y] > dist[cur.Y] + nxt.X)
                {
                    dist[nxt.Y] = dist[cur.Y] + nxt.X;
                    pq.push({dist[nxt.Y], nxt.Y});
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (dist[i] != INT_MAX)
            {
                maxtime = max(maxtime, dist[i]);
                cnt++;
            }
        }

        cout << cnt << ' ' << maxtime << '\n';
    }
}