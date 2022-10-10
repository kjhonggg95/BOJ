#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using pii = pair<int,int>;

#define X first
#define Y second

vector<pair<int,pii>> edge;

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
    memset(p, -1, sizeof(p));
    int n, m, best = 0, worst = 0, cnt = 0;
    cin >> n >> m;
    
    for(int i = 0;i<m+1;i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        edge.push_back({cost,{a,b}});
    }

    // √÷æ«
    sort(edge.begin(), edge.end());
    for(int i = 0;i<edge.size();i++)
    {
        if(!diff(edge[i].Y.X, edge[i].Y.Y)) continue;
        if(edge[i].X == 0) worst++;
        cnt++;
        if(cnt == n) break;
    }

    // √÷¿˚
    memset(p, -1, sizeof(p));
    sort(edge.begin(), edge.end(), greater<>());
    cnt = 0;
    for(int i = 0;i<edge.size();i++)
    {
        if(!diff(edge[i].Y.X, edge[i].Y.Y)) continue;
        if(edge[i].X == 0) best++;
        cnt++;
        if(cnt == n) break;
    }

    cout << worst*worst - best*best;
}