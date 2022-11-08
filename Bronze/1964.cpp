#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    fastio;
    int n;
    cin >> n;
    vector<int> v;
    
    v.push_back(5);
    for(int i = 1;i<n;i++)
        v.push_back((v[i - 1] + (i+1)*3 + 1) % 45678);
    cout << v[n-1];
}