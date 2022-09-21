#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

set<string> s;

int main()
{
	fastio;
	int n, m, cnt = 0;
	string str;
	cin >> n >> m;
	for(int i = 0;i<n;i++)
	{
		cin >> str;
		s.insert(str);
	}

	for(int i = 0;i<m;i++)
	{
		cin >> str;
		if(s.count(str))
			cnt++;
	}

	cout << cnt;

	return 0;
}
