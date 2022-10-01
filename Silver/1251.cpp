#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    fastio;
    vector<string> v;
    string s;
    cin >> s;

    // i = 두번째 단어 시작
    // j = 세번째 단어 시작
    for(int i = 1;i<s.size() - 1;i++)
    {
        for(int j = i+1;j<s.size();j++)
        {
            string str[3];
            str[0] = s.substr(0,i);
            str[1] = s.substr(i,j - i);
            str[2] = s.substr(j, s.size() - j);

            for(int k = 0;k<3;k++)
                reverse(str[k].begin(),str[k].end());
            
            v.push_back(str[0].append(str[1]).append(str[2]));
        }
    }

    sort(v.begin(), v.end());

    cout << v[0];
}