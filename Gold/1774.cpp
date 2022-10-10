#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;

#define X first
#define Y second

vector<pii> pos;
vector<pair<double,pii>> edge;

int p[1005];

int find(int a)
{
    if(p[a] < 0) return a;
    return p[a] = find(p[a]);
}

bool diff(int a, int b)
{
    a = find(a); b = find(b);
    if(a == b) return false;
    p[b] = a;
    return true;
}

int main()
{
    fastio;
    cout << fixed;
    cout.precision(2);
    memset(p, -1, sizeof(p));
    int n, m, cnt = 0;
    double ans = 0;
    cin >> n >> m;
    for(int i = 0;i<n;i++)
    {
        int x, y;
        cin >> x >> y;
        pos.push_back({x,y});
    }

    for(int i = 0;i<n-1;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            double dist = sqrt((pos[i].X - pos[j].X) * (pos[i].X - pos[j].X)
                                + (pos[i].Y - pos[j].Y) * (pos[i].Y - pos[j].Y));
            edge.push_back({dist,{i,j}});
        }
    }

    sort(edge.begin(), edge.end());

    for(int i = 0;i<m;i++)
    {
        int a, b;
        cin >> a >> b;
        diff(a-1,b-1);
        cnt++;
    }

    for(int i = 0;i<edge.size();i++)
    {
        if(!diff(edge[i].Y.X, edge[i].Y.Y)) continue;
        ans += edge[i].X;
        cnt++;
        if(cnt == n-1) break;
    }

    cout << ans;
}