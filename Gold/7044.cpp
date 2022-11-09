#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

#define all(v) v.begin(), v.end()
#define X first
#define Y second
using pii = pair<int,int>;

vector<pair<int,pii>> edge;
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
    int n, m;
    cin >> n >> m;
    for(int i =0;i<m;i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({c,{a,b}});
    }

    sort(all(edge), greater<>());

    int cnt = 0, tot = 0;

    for(auto e : edge)
    {
        if(!diff(e.Y.X, e.Y.Y)) continue;
        tot += e.X;
        cnt++;

        if(cnt == n-1)
        {
            cout << tot;
            return 0;
        }
    }

    cout << "-1";
}