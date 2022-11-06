#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    fastio;
    int n;
    cin >> n;
    vector<int> v(n); // 2 4 -10 4 -9
    for(int i = 0;i<n;i++)
        cin >> v[i];
    
    vector<int> v2(v);

    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(),v2.end()), v2.end()); // -10 -9 2 4

    for(auto& e : v)
        cout << lower_bound(v2.begin(),v2.end(), e) - v2.begin() <<  ' ';
}