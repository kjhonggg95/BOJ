#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

#define all(v) v.begin(), v.end()
#define X first
#define Y second
using pii = pair<int,int>;

int p[100'001];
vector<pair<int,pii>> edge;
vector<int> v[100'001];
vector<int> path;
map<pii,int> mp;
bool vis[100'001];

int n, m, st, en;
int sum = INT_MAX;

void dfs(int cur)
{
    if(cur == en)
    {        
        for(int i = 0;i<path.size()-1;i++)
            sum = min(sum, mp[{path[i],path[i+1]}]);
        return;
    }

    for(auto nxt : v[cur])
    {
        if(vis[nxt]) continue;
        path.push_back(nxt);
        vis[nxt] = true;
        dfs(nxt);
        path.pop_back();
        vis[nxt] = false;
    }
}

int find(int a)
{
    if(p[a] < 0) return a;
    return p[a] = find(p[a]);
}

bool diff(int a, int b)
{
    int pa = find(a);
    int pb = find(b);
    if(pa == pb) return false;
    v[a].push_back(b);
    v[b].push_back(a);
    p[pb] = pa;
    return true;
}

int main()
{
    fastio;
    memset(p, -1, sizeof(p));
    cin >> n >> m >> st >> en;

    for(int i = 0;i<m;i++)
    {
        int u, v, k;
        cin >> u >> v >> k;
        edge.push_back({k,{u,v}});
        mp[{u,v}] = k;
        mp[{v,u}] = k;
    }

    sort(edge.begin(), edge.end(), greater<>());
    
    int cnt;

    for(auto e : edge)
    {
        if(!diff(e.Y.X, e.Y.Y)) continue;
        cnt++;
        if(cnt == n-1) break;
    }

    path.push_back(st);
    vis[st] = true;
    dfs(st);
    
    if(sum == INT_MAX)
        cout << 0;
    else   
        cout << sum;
}