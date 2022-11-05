// 시간복잡도 O(N^2) LIS

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int arr[1001];
int dp[1001];

int main()
{
    fastio;
    int n;
    cin >> n;
    for(int i = 0 ; i<n;i++)
        cin >> arr[i];

    for(int i = 0;i<n;i++)
    {
        dp[i] = 1;
        for(int j = 0;j<n;j++)
            if(arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
    }

    cout << *max_element(dp,dp + 1000);
}