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

    for(int h = 0;h<=256;h++) // �� ���� 0~256����
    {
        int tot = 0;    // �۾� �ð�
        int block = b;  // ��� ����
        bool flag = true;

        memset(temp, 0, sizeof(temp));
        memcpy(temp, arr, sizeof(arr));

        // ��� ������
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

        // ��� �ױ�
        for(int i = 0;i<n;i++)
        {
            if(!flag) break;
            for(int j = 0;j<m;j++)
            {
                if(temp[i][j] >= h) continue;
                if(block < h - temp[i][j]) 
                {
                    flag = false;
                    continue; // ��� ����
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