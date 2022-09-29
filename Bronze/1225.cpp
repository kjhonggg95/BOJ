#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    fastio;
    string a,b;
    long long sum = 0;
    cin >> a >> b;
    for(int i = 0;i<a.length();i++)
        for(int j = 0;j<b.length();j++)
            sum += (a[i] - '0') * (b[j] - '0');

    cout << sum;
}