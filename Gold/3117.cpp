#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 100001;
const int MAX_D = 30;

int nxt[MAX][MAX_D];
int arr[MAX];

int main()
{
    fastio;
    int n, k, m;
    cin >> n >> k >> m; m--;

    for(int i = 1;i<=n;i++)
        cin >> arr[i];   // i번째 학생이 처음 시청하는 동영상 번호

    for(int i = 1;i<=k;i++)
        cin >> nxt[i][0]; 
    
    for(int j = 1;j<MAX_D;j++)
        for(int i = 1;i<=k;i++)
            nxt[i][j] = nxt[nxt[i][j-1]][j-1];

    for(int i = 1;i<=n;i++)
    {
        int a = arr[i];
        int b = m;
        for(int j = 0;b;j++)
        {
            if(b & 1) a = nxt[a][j];
            b >>= 1;
        }

        cout << a << ' ';
    }
}