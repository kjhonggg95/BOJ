#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    fastio;
    int n;
    cin >> n;
    int st = 1, en = 1, cnt = 1;
    while(1)
    {
        if(st <= n && n <= en)
        {
            cout << cnt;
            return 0;
        }

        st = en + 1;
        en = (st - 1) + 6 * cnt;
        cnt++;
    }
}