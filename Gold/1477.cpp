#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int n, m, l;
vector<int> v;

bool check(int mid)
{
    int cnt = 0;

    for(int i = 1;i<v.size();i++)
        cnt += (v[i] - v[i-1] - 1) / mid;

    return cnt <= m;
}

int main()
{
    cin >> n >> m >> l; // 6 7 800
    v.resize(n+2);
    v[0] = 0; v[n+1] = l;
    for(int i = 1;i<=n;i++)
        cin >> v[i];    // 622 411 201 555 755 82

    sort(v.begin(), v.end()); // 0 82 201 411 555 622 755 800

    int lo = 0, hi = l; // 0, 800 (휴게소가 들어설 수 있는 위치 : [1, 799])

    // 구간
    // F F F F ... F T(HI) T ... T T T T
    // cnt <= m 을 만족하는 구간 중 최소값 찾기
    while(lo + 1 < hi)
    {
        int mid = (lo + hi) / 2; // 간격

        if(!check(mid)) lo = mid; // 휴게소 줄여야함 -> 간격 늘리기
        else hi = mid;            // 휴게소 늘려야함 -> 간격 줄이기
    }

    cout << hi;
}