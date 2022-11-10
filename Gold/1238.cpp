#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

using pii = pair<int, int>;

#define X first
#define Y second

int d[1005];
int start[1001];
int back[1001];

vector<pii> adj[1001];

int main()
{
    fastio;
    int n, m, x;
    cin >> n >> m >> x;
    for(int i = 0;i<m;i++)
    {
        int a, b, c;
        cin >> a >> b >> c; // ��� ���� ���
        adj[a].push_back({c,b}); // ��� ����
    }

    for(int i = 1;i<=n;i++) // �� �л����� x���� ���µ� �ɸ��� �ð� ���
    {
        int st = i, en = x; // ������, ����
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        fill(d, d+1001, INT_MAX);
        d[st] = 0;
        pq.push({d[st],st}); // (0, ������)

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

        start[st] = d[en];
    }

    for(int i = 1;i<=n;i++) // �� �л����� x���� ���µ� �ɸ��� �ð� ���
    {
        int st = x, en = i; // ������, ����
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        fill(d, d+1001, INT_MAX);
        d[st] = 0;
        pq.push({d[st],st}); // (0, ������)

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

        back[en] = d[en];
    }


    int max_dist = 0;

    for(int i = 1;i<=n;i++)
    {
        int tot = start[i] + back[i];
        max_dist = max(max_dist, tot);
    }

    cout << max_dist;
}