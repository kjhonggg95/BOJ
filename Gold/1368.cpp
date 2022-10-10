// 1368번: 물대기
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;

#define X first
#define Y second

vector<ll> direct;
vector<pair<ll,pii>> edge;

int p[305];

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
    ll n, ans = 0, cnt = 0;
    cin >> n;

    direct.resize(n);

    for(int i = 1;i<=n;i++)
    {
        int cost;
        cin >> cost;
        edge.push_back({cost,{0,i}});
    }
    
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=n;j++)
        {
            int cost;
            cin >> cost;
            if(j>=i) continue;
            edge.push_back({cost,{i,j}});
        }

    

    sort(edge.begin(), edge.end());

    for(auto e : edge)
    {
        if(!diff(e.Y.X, e.Y.Y)) continue;
        ans += e.X;
        cnt++;
        if(cnt == n) break;
    }

    cout << ans;
}