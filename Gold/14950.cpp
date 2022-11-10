#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using pii = pair<int, int>;

#define X first
#define Y second

vector<pair<int, pii>> edge;
int p[10001];

int find(int a)
{
    if (p[a] < 0) return a;
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
    int n, m, t;
    cin >> n >> m >> t;

    memset(p, -1, sizeof(p));

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({c, {a, b}});
    }

    sort(edge.begin(), edge.end());

    int tot = 0;
    int cnt = 0;

    for (auto e : edge)
    {
        if (!diff(e.Y.X, e.Y.Y)) continue;
        tot += (e.X + cnt * t);
        cnt++;
        if (cnt == n - 1)
        {
            cout << tot;
            return 0;
        }
    }
}