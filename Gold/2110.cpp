#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;

vector<ll> v;
int n, c;

bool check(int mid)
{
    ll cnt = 1;   // ù ��° �� ������ ī��Ʈ
    ll cur = v[0]; // ù ��° �� ����

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

    // ���� ���� ��谪 ����
    ll lo = 0;                   
    ll hi = v[n - 1] - v[0] + 1;
    
    while (lo + 1 < hi)
    {
        ll mid = (lo + hi) / 2; // ����

        if (!check(mid))
            hi = mid; // ������ ���� �� -> ���� ���̱�
        else
            lo = mid; // ������ ���� �� -> ���� �ø���
    }

    cout << lo;
}