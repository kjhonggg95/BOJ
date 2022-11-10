#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using pii = pair<int, int>;
using ll = long long;

#define all(v) v.begin(), v.end()
#define X first
#define Y second

vector<pii> pos;
vector<pair<ll,pii>> edge;
int p[1001];

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
    memset(p, -1, sizeof(p));
    int n;
    cin >> n;
    pos.resize(n+1);
    for(int i = 1;i<=n;i++)
    {
        int x, y;
        cin >> x >> y;
        pos[i] = {x,y};
    }

    for(int i = 1;i<=n-1;i++)
    {
        for(int j = i+1;j<=n;j++)
        {
            ll dist = (pos[i].X - pos[j].X) * (pos[i].X - pos[j].X)
                + (pos[i].Y - pos[j].Y) * (pos[i].Y - pos[j].Y);
            edge.push_back({dist,{i,j}});
        }
    }

    sort(all(edge));

    ll maxdist = 0;
    int cnt = 0;

    for(auto e : edge)
    {
        if(!diff(e.Y.X, e.Y.Y)) continue;
        maxdist = max(e.X, maxdist);
        cnt++;

        if(cnt == n-1)
        {
            cout << maxdist;
            return 0;
        }
    }   
}