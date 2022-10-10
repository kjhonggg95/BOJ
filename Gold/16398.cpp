// 16398번: 행성 연결
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;

#define X first
#define Y second

vector<pair<ll,pii>> edge;

int p[1005];

int find(int a)
{
    if(p[a] < 0) return a;
    return p[a] = find(p[a]);
}

bool diff(int a, int b) // 같은 그룹에 속해 있는가
{
    a = find(a); b = find(b);
    if(a == b) return false;
    p[b] = a;
    return true;
}

int main()
{
    fastio;
    ll n, ans = 0, cnt = 0;
    cin >> n;
    memset(p, -1, sizeof(p));
    for(int i = 0;i<n;i++)
    {
        for(int  j = 0;j<n;j++)
        {
            int cost;
            cin >> cost;
            if(j>=i) continue;
            edge.push_back({cost,{i,j}});
        }
    }

    sort(edge.begin(), edge.end());

    for(int i = 0;i<edge.size();i++)
    {
        if(!diff(edge[i].Y.X, edge[i].Y.Y)) continue;
        ans += edge[i].X;
        cnt++;
        if(cnt == n - 1) break;
    }

    cout << ans;
}