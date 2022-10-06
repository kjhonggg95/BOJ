#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using pii = pair<int, int>;

#define X first
#define Y second

vector<pii> v;
bool vis[100005];
int parent[100005];
int dest;

void findDest(int now)
{
	if (now == -1)
		return;

	findDest(v[now].X);
	dest = now;
	findDest(v[now].Y);
}

void dfs(int now, int en, int dist)
{
	// ���� ��ġ�� ����� ���� �ڽ� ��尡 �����ϰ� ���� �湮���� �ʾҴٸ�, ���� �ڽ� ���� �̵��Ѵ�.
	if (v[now].X != -1 && !vis[v[now].X])
	{
		vis[v[now].X] = true;
		dfs(v[now].X, en, dist + 1);
	}

	// �׷��� �ʰ� ���� ��ġ�� ����� ������ �ڽ� ��尡 �����ϰ� ���� �湮���� �ʾҴٸ�, ������ �ڽ� ���� �̵��Ѵ�.
	if (v[now].Y != -1 && !vis[v[now].Y])
	{
		vis[v[now].Y] = true;
		dfs(v[now].Y, en, dist + 1);
	}

	// �׷��� �ʰ� ���� ��尡 ���� ���� ��ȸ�� ���̶��, ���� ���� ��ȸ�� �����Ѵ�.
	if (now == en)
	{
		cout << dist << '\n';
		exit(0);
	}

	// �׷��� �ʰ� �θ� ��尡 �����Ѵٸ�, �θ� ���� �̵��Ѵ�.
	if (parent[now] != -1)
		dfs(parent[now], en, dist + 1);
}

int main()
{
	fastio;
	int n;
	cin >> n;
	v.resize(n + 1);
	memset(parent, -1, sizeof(parent));
	for (int i = 1; i <= n; i++)
	{
		int p, l, r;
		cin >> p >> l >> r;
		parent[l] = parent[r] = p;
		v[p] = { l,r };
	}

	findDest(1);

	dfs(1, dest, 0); // 1, 7
}