#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

map<string, vector<string>> m1;
map<string, string> m2;

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 0;i<n;i++)
    {            
        vector<string> v;
        string group;
        int n;
        cin >> group >> n;

        for(int j = 0;j<n;j++)
        {
            string member;
            cin >> member;
            v.push_back(member);
            m2[member] = group;
        }
        
        sort(v.begin(), v.end());
        m1[group] = v;
    }

    for(int i = 0;i<m;i++)
    {
        int n;
        string str;
        cin >> str >> n;

        if(n == 0) // 그룹명
            for(auto e : m1[str])
                cout << e << '\n';
        if(n == 1) // 멤버명
            cout << m2[str] << '\n';
    }
}