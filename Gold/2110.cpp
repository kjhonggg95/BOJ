#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;

int main()
{
    fastio;
    int n,c;
    cin >> n >> c; // 5 3
    vector<ll> v(n);
    for(int i = 0; i<n;i++)
        cin >> v[i]; // 1 2 8 4 9
    
    sort(v.begin(), v.end()); // 1 2 4 8 9

    ll st = 1;             // 시작 거리 // 1 // 1 // 2 // 3
    ll en = v[n-1] - v[0]; // 끝 거리   // 8 // 3 // 3 // 3

    while(st <= en)
    {
        ll cnt = 1;
        ll mid = (st + en ) / 2; // 간격
        ll cur = v[0];

        for(int i = 1;i< n;i++)
        {
            if(v[i] - cur >= mid)
            {
                cnt++;
                cur = v[i];
            }
        }

        if(cnt >= c) // 공유기 수 줄이기 == 간격 넓히기
            st = mid + 1;
        else // 공유기 수 늘리기 == 간격 좁히기
            en = mid - 1; // 3
    }

    cout << (st + en) / 2;
}