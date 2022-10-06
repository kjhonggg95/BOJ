#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int q[2000000];
int front, back;

int main()
{
    fastio;
    int n;
    cin >> n;
    while(n--)
    {
        string cmd;
        cin >> cmd;

        if(cmd == "push")
        {
            int x;
            cin >> x;
            q[back++] = x;
        }
        if(cmd == "pop")
        {
            if(back == front)
                cout << "-1\n";
            else
                cout << q[front++] << '\n';
        }
        if(cmd == "size")
        {
            cout << back - front << '\n';
        }
        if(cmd == "empty")
        {
            if(front == back)
                cout << "1\n";
            else
                cout << "0\n";
        }
        if(cmd == "front")
        {
            if(front == back)
                cout << "-1\n";
            else
                cout << q[front] << '\n';
        }
        if(cmd == "back")
        {
            if(front == back)
                cout << "-1\n";
            else
                cout << q[back - 1] << '\n';
        }

        // cout << "cmd : " << cmd << ", front : " << front << ", back : " << back << '\n';
    }
}