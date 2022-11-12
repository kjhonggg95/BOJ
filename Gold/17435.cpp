#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 500001;
const int MAX_D = 19;

int nxt[MAX][MAX_D]; // next[i][j] = ���� i���� 2^j�� �̵��� ���� ����

int main()
{
    fastio;
    int m;
    cin >> m;

    for (int i = 1; i <= m; i++)
        cin >> nxt[i][0];

    for (int j = 1; j < MAX_D; j++)
        for (int i = 1; i <= m; i++)
            nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];

    int q;
    cin >> q;

    // n = 1000 �� ��,
    // 1000(10) = 1111101000(2)
    // 2^9  2^8  2^7  2^6  2^5  --  2^3  --  --  --
    // --> 1000(2^9 + 2^8 + 2^8 + 2^6 + 2^5 + 2^3) ��° �Լ�
    // j == 3, 5, 6, 7, 8, 9 �� �� (j��° bit�� ��������)
    //
    // nxt[x][3] : nxt[x][0] ���� 2^3��ŭ ���� ��
    // nxt[nxt[x][3]][5] : nxt[x][3] ���� 2^5��ŭ ���� ��
    // ...
    // nxt[nxt[x][8]][9] : nxt[x][8] ���� 2^9��ŭ ���� ��
    //
    // --> nxt[x][0] ���� 1000�� �̵��� ���� ���� ��������.  
    while (q--)
    {
        int n, x; // n��° ��øf
        cin >> n >> x;

        for (int j = 0; n > 0; j++)
        {
            if(n & 1) x = nxt[x][j];
            n >>= 1;
        }

        cout << x << '\n';
    }
}