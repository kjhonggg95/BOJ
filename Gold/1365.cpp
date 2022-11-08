#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

#define all(v) v.begin(), v.end()

int main()
{
    fastio;
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> lis;
    for(int i = 0;i<n;i++)
        cin >> arr[i];
    
    lis.push_back(arr[0]);

    for(int i = 1;i<n;i++)
        if(lis.back() < arr[i]) lis.push_back(arr[i]);
        else *lower_bound(all(lis), arr[i]) = arr[i];

    cout << n - lis.size();
}

// 10 20 15 30 40 50 25
// 10 
// 10 20
// 10 15
// 10 15 30
// 10 15 30 40
// 10 15 30 40 50
// 10 15 25
