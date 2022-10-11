#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int day[100005];
int sum[100005];
int maxtemp = -1e9;

int main()
{
    fastio;
    int n,k;
    cin >> n >> k;
    for(int i = 1;i<=n;i++)
    {
        cin >> day[i];
        sum[i] = sum[i-1] +day[i];
    }

    for(int i = k;i<=n;i++)
        if(sum[i]-sum[i-k] > maxtemp)
            maxtemp = sum[i] - sum[i-k];

    cout << maxtemp;
}