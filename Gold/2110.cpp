#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;

vector<ll> v;
int n, c;

bool check(int mid)
{
    ll cnt = 1;   // 첫 번째 집 공유기 카운트
    ll cur = v[0]; // 첫 번째 집 기준

    for (int i = 1; i < n; i++)
    {
        if (v[i] - cur >= mid)
        {
            cnt++;
            cur = v[i];
        }
    }
    return cnt >= c;
}

int main()
{
    fastio;
    cin >> n >> c;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end()); // 1 2 4 8 9

    // 간격 범위 경계값 포함
    ll lo = 0;                   
    ll hi = v[n - 1] - v[0] + 1;
    
    while (lo + 1 < hi)
    {
        ll mid = (lo + hi) / 2; // 간격

        if (!check(mid))
            hi = mid; // 공유기 적을 때 -> 간격 줄이기
        else
            lo = mid; // 공유기 많을 때 -> 간격 늘리기
    }

    cout << lo;
}