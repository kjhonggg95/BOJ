#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    fastio;
    int t;
    cin >> t;
    while(t--)
    {
        bool flag = false;
        int k;
        cin >> k;
        vector<string> v(k);
        for(int i = 0;i<k;i++)
            cin >> v[i];
        
        for(int i = 0;i<k-1;i++)
        {
            for(int j = i+1;j<k;j++)
            {
                string a1, a2;
                a1.append(v[i]);
                a1.append(v[j]);
                a2 = a1;
                reverse(a2.begin(), a2.end());

                if(a1 == a2)
                {
                    cout << a1 << '\n';
                    flag = true;
                    break;
                }

                string b1, b2;
                b1.append(v[j]);
                b1.append(v[i]);
                b2 = b1;
                reverse(b2.begin(), b2.end());

                if(b1 == b2)
                {
                    cout << b1 << '\n';
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }

        if(!flag)
            cout << "0" << '\n';
    }
}