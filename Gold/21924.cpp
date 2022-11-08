#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

#define X first
#define Y second
#define all(v) v.begin(), v.end()

using pii = pair<int, int>;
int p[100001];
vector<pair<int,pii>> edge;

int find(int a)
{
    if(p[a] < 0) return a;
    return p[a] = find(p[a]);
}

bool diff(int a, int b)
{
    a = find(a); b = find(b);
    if(a == b) return false; // 같은 집합 내
    p[b] = a;
    return true;
}

int main()
{
    fastio;
    memset(p, -1, sizeof(p));

    int n, m;
    long long tot = 0;
    cin >> n >> m;
    for(int i = 0;i<m;i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        tot += cost;
        edge.push_back({cost,{a,b}});
    }   

    sort(all(edge));

    long long ans = 0;
    int cnt = 0;

    for(auto& e : edge)
    {
        if(!diff(e.Y.X, e.Y.Y)) continue;
        ans += e.X;
        cnt++;

        if(cnt == n - 1)
        {
            cout << tot - ans;
            return 0;
        }
    }

    cout << "-1";
}