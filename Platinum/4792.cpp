#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using pii = pair<int, int>;

#define X first
#define Y second

vector<pair<char, pii>> edge;
int p[1005];

bool blueMaxSort(pair<char, pii>& a, pair<char, pii>& b)
{
    return a.first < b.first;
}

bool blueMinSort(pair<char, pii>& a, pair<char, pii>& b)
{
    return a.first > b.first;
}

int find(int a)
{
    if (p[a] < 0) return a;
    return p[a] = find(p[a]);
}

bool diff(int a, int b)
{
    a = find(a); b = find(b);
    if (a == b) return false;
    p[b] = a;
    return true;
}

int main()
{
    fastio;
    while (1)
    {
        int n, m, k;
        cin >> n >> m >> k;
        if (n + m + k == 0)
            break; // 종료조건

        char c;
        int f, t, blueMax = 0, blueMin = 0, cnt = 0;

        for (int i = 0; i < m; i++)
        {
            cin >> c >> f >> t;
            edge.push_back({ c, {f,t} });
        }


        // 파란 간선 최대
        memset(p, -1, sizeof(p));
        sort(edge.begin(), edge.end(), blueMaxSort);

        for (int i = 0; i < m; i++)
        {
            if (!diff(edge[i].Y.X, edge[i].Y.Y)) continue;
            if (edge[i].first == 'B') blueMax++;
            cnt++;
            if (cnt == n - 1) break;
        }

        // 파란 간선 최소
        cnt = 0;
        memset(p, -1, sizeof(p));
        sort(edge.begin(), edge.end(), blueMinSort);
        for (int i = 0; i < m; i++)
        {
            if (!diff(edge[i].Y.X, edge[i].Y.Y)) continue;
            if (edge[i].first == 'B') blueMin++;
            cnt++;
            if (cnt == n - 1) break;
        }

        cout << (blueMin <= k && k <= blueMax) << '\n';
        edge.clear();
    }
}