#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int arr[11][11];
bool used[11];
int maxsum;

void dfs(int pos, int sum)
{
    if(pos == 11)
    {
        if(sum > maxsum)
            maxsum = sum;
        return;
    }

    for(int i = 0;i<11;i++)
    {
        if(arr[pos][i] == 0) continue;
        if(used[i]) continue;

        used[i] = true;
        dfs(pos + 1, sum + arr[pos][i]);
        used[i] = false;
    }
}

int main()
{
    fastio;
    int t;
    cin >> t;
    while(t--)
    {
        for(int i = 0;i<11;i++)
            for(int j = 0;j<11;j++)
                cin >> arr[i][j];
        
        dfs(0,0);

        cout << maxsum << '\n';

        memset(arr,0,sizeof(arr));
        memset(used, 0, sizeof(used));
        maxsum = 0;
    }
}