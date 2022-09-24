#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;

ll n, m;
vector<ll> v;

bool check(ll mid)
{
    ll sum = 0;

    for(auto& e : v)
    {
        if(mid <= e)
            sum += mid;
        else
            sum += e; // »óÇÑ¾×
    }
 
    return sum <= m;
}

int main()
{
    fastio;
    cin >> n;
    v.resize(n);
    for(int i = 0;i<n;i++)
        cin >> v[i];
    cin >> m;
    ll lo = 0;
    ll hi = *max_element(v.begin(), v.end()) + 1;

    while(lo + 1 < hi)
    {
        ll mid = (lo + hi) / 2;

        if(!check(mid)) hi = mid;
        else lo = mid;
    }

    cout << lo;
}