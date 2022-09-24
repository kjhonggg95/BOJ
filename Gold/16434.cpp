#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;

typedef struct Info
{
    ll a; // 1 ���� 2 ����
    ll b; // m���ݷ� / w���ݷ�����
    ll c; // m����� / w���������
} info;

ll n, m;
vector<info> v;


bool check(ll hp)
{
    ll maxhp = hp;
    ll attack = m;

    for (auto e : v)
    {
        if (e.a == 1) // ���͹�
        {
            // ��� ���� Ƚ��
            int atkcnt = (ceil)(e.c / (double)attack);
            // ���� ���� Ƚ�� == atkcnt - 1

            hp -= (e.b * (atkcnt - 1));

            if (hp <= 0)
                return false;
        }
        else // ������
        {
            attack += e.b;
            hp = min(hp + e.c, maxhp);
        }
    }

    return true;
}

int main()
{
    fastio;
    cin >> n >> m; // �� ���� , �ʱ� ���ݷ�
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].a >> v[i].b >> v[i].c;

    ll lo = 0;
    ll hi = LLONG_MAX;

    while (lo + 1 < hi)
    {
        ll mid = (lo + hi) / 2;

        if (!check(mid))
            lo = mid;
        else
            hi = mid;
    }

    cout << hi;
}
