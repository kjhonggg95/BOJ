#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int arr[1025][1025];
int sum[1025][1025];

int main()
{
    fastio;
    int n,m;
    cin >> n >>m;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            cin >> arr[i][j];
            sum[i][j] = sum[i][j-1] + arr[i][j];
        }
    }

    while(m--)
    {
        int x1,y1,x2,y2, ans = 0;
        cin >> x1 >> y1 >> x2 >> y2;

        for(int i = x1;i<=x2;i++)
            ans += (sum[i][y2] - sum[i][y1 - 1]);
        cout << ans << '\n';
    }
}