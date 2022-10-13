#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

map<string, int> mp;

int main()
{
    fastio;
    cout << fixed;
    cout.precision(4);
    string str;
    int tot = 0;
    while (1)
    {
        getline(cin, str);
        if (cin.eof() == true) break;
        mp[str]++;
        tot++;
    }

    for (auto e : mp)
        cout << e.first << ' ' << (double)e.second / tot * 100<< '\n';

}