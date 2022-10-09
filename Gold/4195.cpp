#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int p[200005];

int find(int a)
{
    if(p[a] < 0) return a;
    p[a] = find(p[a]);
    return p[a];
}

void merge(int a, int b)
{
    a = find(a); b = find(b);
    if(a == b) return;
    p[a] += p[b];
    p[b] = a;
}

int main()
{
    fastio;
    int t; cin >> t;
    while(t--)
    {
        map<string, int> mp;
        int f, cnt = 1;
        cin >> f;
        memset(p, -1, sizeof(p));
        for(int i = 0;i<f;i++)
        {
            string a, b;
            cin >> a >> b;
            if(!mp[a]) mp[a] = cnt++;
            if(!mp[b]) mp[b] = cnt++;
            merge(mp[a], mp[b]);
            cout << abs(p[find(mp[a])]) << '\n';
        }
    }
}