#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

#define X first
#define Y second
#define all(v) v.begin(), v.end()

using pii = pair<int, int>;

int p[1001];
int sex[1001];

vector<pair<int,pii>> edge;

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
    for(int i = 1; i<=n;i++)
    {
        char c;
        cin >> c;
        if(c == 'M') sex[i] = 1; // ³²
        else sex[i] = 2;    // ¿©
    }

    for(int i = 0;i<m;i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;

        if(sex[a] == sex[b]) continue;

        edge.push_back({cost,{a,b}});
    }

    sort(all(edge));

    int sum = 0;
    int cnt = 0;

    for(auto& e : edge)
    {
        if(!diff(e.Y.X, e.Y.Y)) continue;
        sum += e.X;

        cnt++;
        if(cnt == n-1)
        {
            cout << sum;
            return 0;
        }
    }

    cout << "-1";
}