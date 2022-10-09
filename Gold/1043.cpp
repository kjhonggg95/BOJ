#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

bool know[55];
int p[55];
vector<vector<int>> party;

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
    if(know[a])
        p[b] = a;
    else
        p[a] = b;
}

int main()
{
    fastio;
    int n, m, cnt = 0;
    cin >> n >> m;
    fill(p, p+n+1, -1);
    party.resize(m);

    int k; cin >> k;
    
    for(int i = 0;i<k;i++)
    {
        int x; cin >> x;
        know[x] = true;    
    }

    for(int i = 0;i<m;i++) // 파티
    {
        int a; cin >> a;
        for(int  j = 0;j<a;j++)
        {
            int x;
            cin >> x;
            party[i].push_back(x); // 파티에 오는 사람
        }

        for(int j = 1;j<party[i].size();j++)
            merge(party[i][0], party[i][j]);
    }

    for(int i = 0;i<party.size();i++)
    {
        for(int j = 0;j<party[i].size();j++)
        {
            if(know[find(party[i][j])])
            {
                m--;
                break;
            }
        }
    }

    cout << m;
}