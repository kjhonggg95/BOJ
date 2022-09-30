#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

queue<string> q;

int main()
{
    fastio;
    string s, t;
    cin >> s >> t;

    while(1)
    {
        if(s.length() == t.length())
        {
            if(s == t)
            {
                cout << 1;
                return 0;
            }
            break;
        }

        if(t[t.length() - 1] == 'A')
            t.pop_back();
        else // ³¡ B
        {
            t.pop_back();
            reverse(t.begin(),t.end());
        }
    }

    cout << 0;
    return 0;
}