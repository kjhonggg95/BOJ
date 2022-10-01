#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    fastio;
    string s;
    bool underbar = false;
    bool upper = false;
    cin >> s;

    for(auto e : s)
    {
        if(isupper(e))
            upper = true;
        if(!isalpha(e))
            underbar = true;
    }

    // ����� ����
    for(int i = 0;i<s.size()-1;i++)
        if(s[i] == '_' && s[i+1] == '_')
        {
            cout << "Error!";
            return 0;
        }

    // ����ٿ� �빮�ڰ� ���� �ִ� ���
    if(underbar && upper)
    {
        cout << "Error!";
        return 0;
    }

    // ù���� �빮�� / ù���� ����� / ���������� �����
    if(isupper(s[0]) || !isalpha(s[0]) || s[s.size() - 1] == '_')
    {
        cout << "Error!";
        return 0;
    }
    
    for(auto e : s)
        if(e == '_')
            underbar = true;

    if(underbar) // c++ -> java
    {
        string java;
        int st = 0;
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == '_')
            {
                java.append(s.substr(st,i - st));
                st = i + 1;
                s[i+1] = toupper(s[i+1]);
            }
        }

        java.append(s.substr(st, s.size() - st));
        cout << java;
    }
    else // java -> c++
    {
        string cpp;
        int st = 0;
        for(int i = 0;i<s.size();i++)
        {
            if(isupper(s[i]))
            {
                cpp.append(s.substr(st, i - st));
                cpp.append("_");
                st = i;
                s[i] = tolower(s[i]);
            }
        }

        cpp.append(s.substr(st, s.size() - st));
        cout << cpp;
    }
    cout << '\n';
}