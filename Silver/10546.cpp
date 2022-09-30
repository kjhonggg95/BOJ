#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    fastio;
    int n;
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        m[str]++;
    }

    for (int i = 0; i < n - 1; i++)
    {
        string str;
        cin >> str;
        m[str]--;
    }

    for (auto e : m)
    {
        if (e.second % 2 == 1)
        {
            cout << e.first;
            return 0;
        }
    }
}