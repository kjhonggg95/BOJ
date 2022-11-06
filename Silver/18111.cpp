#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using pii = pair<int,int>;

int arr[501][501];
int temp[501][501];

int main()
{
    fastio;
    int n,m,b;
    set<int> s;
    cin >> n >> m >> b;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
        {
            cin >> arr[i][j];
            s.insert(arr[i][j]);
        }
    
    
    int mintime = INT_MAX;
    int maxh = 0;

    for(int h = 0;h<=256;h++) // 땅 높이 0~256까지
    {
        int tot = 0;    // 작업 시간
        int block = b;  // 블록 개수
        bool flag = true;

        memset(temp, 0, sizeof(temp));
        memcpy(temp, arr, sizeof(arr));

        // 블록 깎기부터
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(temp[i][j] <= h) continue;

                block += (temp[i][j] - h);
                tot += (2 * (temp[i][j] - h));
                temp[i][j] = h;
            }
        }

        // 블록 쌓기
        for(int i = 0;i<n;i++)
        {
            if(!flag) break;
            for(int j = 0;j<m;j++)
            {
                if(temp[i][j] >= h) continue;
                if(block < h - temp[i][j]) 
                {
                    flag = false;
                    continue; // 블록 부족
                }    

                block -= (h - temp[i][j]);
                tot += (h - temp[i][j]);
                temp[i][j] = h;
            }
        }

        for(int i = 0;i<n;i++)
        {
            if(!flag) break;
            for(int j = 0;j<m;j++)
                if(temp[i][j] != h)
                {
                    flag = false;
                    break;
                }
        }

        if(!flag) continue;
        
        if(tot < mintime)
        {
            mintime = tot;
            maxh = h;
        }
        else if(tot == mintime && h > maxh)
            maxh = h;
    }

    cout << mintime << ' ' << maxh;
}