#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using pii = pair<int, int>;
using ll = long long;

#define all(v) v.begin(), v.end()
#define X first
#define Y second

vector<pii> adj[1001];
vector<int> path;
int d[1001];
int pre[1001];

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    fill(d, d + n + 1, INT_MAX);
    for(int i = 0;i<m;i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
    }

    int st, en;
    cin >> st >> en;
    d[st] = 0;

    priority_queue<pii> pq;
    pq.push({d[st],st});

    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if(d[cur.Y] != cur.X) continue;
        for(auto nxt : adj[cur.Y])
        {
            if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pre[nxt.Y] = cur.Y;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }

    int cnt = 0;
    int cur = en;

    while(cur != st)
    {
        path.push_back(cur);
        cur = pre[cur];
    }
    path.push_back(cur);

    cout << d[en] << '\n' << path.size() << '\n';
    for(int i = path.size() - 1; i>=0;i--)
        cout << path[i] << ' ';
    cout << '\n';

}