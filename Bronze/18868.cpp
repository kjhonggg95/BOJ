#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    fastio;
    int m,n,cnt=0;
    cin >> m >> n;
    vector<vector<int>> v(m);
    for(int i = 0;i<m;i++)
    {
        vector<int> a(n); // 1 3 2
        
        for(int j = 0;j<n;j++)
            cin >> a[j];

        vector<int> b(a);
        sort(b.begin(),b.end());
        b.erase(unique(b.begin(),b.end()),b.end()); // 1 2 3 

        for(auto& e : a)
            v[i].push_back(lower_bound(b.begin(),b.end(),e) - b.begin());
    }

    for(int i =0;i<m-1;i++)
        for(int j = i+1;j<m;j++)
            for(int k = 0;k<n;k++)
            {
                if(v[i][k] != v[j][k]) break;
                if(k==n-1) cnt++;
            }

    cout << cnt;
}