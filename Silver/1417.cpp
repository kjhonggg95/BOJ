#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

priority_queue<int> pq;

int main()
{
    fastio;
    int n, a, cnt = 0;
    cin >> n >> a;

    

    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        pq.push(x);
    }
    
    while(!pq.empty())
    {
        if(a > pq.top())
        {
            cout << cnt;
            return 0;
        }

        int x = pq.top();
        x--; a++; cnt++;
        pq.pop();
        pq.push(x);
    }

    cout << 0;
}