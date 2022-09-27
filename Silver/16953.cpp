#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using pll = pair<long, long>;
using ll = long long;

#define X first
#define Y second

int main()
{
    ll a,b;
    cin >> a >> b;
    queue<pll> q;
    q.push({a,1});

    while(!q.empty())
    {
        auto cur = q.front();
        ll cnt = cur.Y;
        q.pop();

        if(cur.X == b)
        {
            cout << cur.Y;
            return 0;
        }

        if(cur.first * 2 <= b)
            q.push({cur.X * 2, cnt + 1});
        if(cur.first * 10 + 1 <= b)
            q.push({cur.X * 10 + 1, cnt + 1});
    }   

    cout << -1;
    return 0;
}