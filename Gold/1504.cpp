#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

using pii = pair<int,int>;

#define X first
#define Y second

const int MAX = 1e8;

vector<pii> adj[801];
int d[801];

int main()
{
    fastio;
    int n, e;
    cin >> n >> e;
    for(int i = 0;i<e;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }

    int st = 1, en = n, v1, v2;
    cin >> v1 >> v2;
    
    int tot1 = 0, tot2 = 0;
    
    // 1 -> v1 -> v2 -> n

    // 1 -> v1
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    fill(d, d + n + 1,MAX);
    d[st] = 0;
    pq.push({d[st],st});
    
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();

        if(d[cur.Y] != cur.X) continue;

        for(auto nxt : adj[cur.Y])
        {
            if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }

    tot1 += d[v1];

    // v1 -> v2
    fill(d, d + n + 1,MAX);
    d[v1] = 0;
    pq.push({d[v1],v1});
    
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();

        if(d[cur.Y] != cur.X) continue;

        for(auto nxt : adj[cur.Y])
        {
            if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }

    tot1 += d[v2];

    // v2 -> n
    fill(d, d + n + 1,MAX);
    d[v2] = 0;
    pq.push({d[v2],v2});
    
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();

        if(d[cur.Y] != cur.X) continue;

        for(auto nxt : adj[cur.Y])
        {
            if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }

    tot1 += d[n];

    // 1 -> v2 -> v1 -> n
    // 1 -> v2
    fill(d, d + n + 1,MAX);
    d[st] = 0;
    pq.push({d[st],st});
    
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();

        if(d[cur.Y] != cur.X) continue;

        for(auto nxt : adj[cur.Y])
        {
            if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }

    tot2 += d[v2];

    // v2 -> v1
    fill(d, d + n + 1,MAX);
    d[v2] = 0;
    pq.push({d[v2],v2});
    
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();

        if(d[cur.Y] != cur.X) continue;

        for(auto nxt : adj[cur.Y])
        {
            if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }

    tot2 += d[v1];

    // v1 -> n
    fill(d, d + n + 1,MAX);
    d[v1] = 0;
    pq.push({d[v1],v1});
    
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();

        if(d[cur.Y] != cur.X) continue;

        for(auto nxt : adj[cur.Y])
        {
            if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }

    tot2 += d[n];

    int ans = min(tot1,tot2);
    if(ans >= MAX)
        cout << -1;
    else
        cout << ans;
}