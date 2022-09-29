#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    fastio;
    int x1, x2, y1, y2;
    int x3, x4, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    int r = max(x2, x4) - min(x1, x3);
    int c = max(y2, y4) - min(y1, y3);
    int l = max(r, c);
    cout << l * l;
}