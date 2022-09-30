#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using ull = unsigned long long;

ull gcd(ull a, ull b)
{
    ull c = a % b;
    while(c!=0)
    {
        a = b;
        b = c;
        c = a % b;
    }

    return b;
}

int main()
{
    fastio;
    ull a, b;
    cin >> a >> b;
    
    for(int i = 0;i<gcd(a,b);i++)
        cout << "1";
}