#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

#define all(v) v.begin(), v.end()

int n,q,m;
int sz = 1;

vector<vector<int>> tree;

void build()
{
    for(int i = sz - 1;i>0;i--)
    {
        tree[i].resize(tree[i*2].size() + tree[i*2+1].size());
        merge(all(tree[i*2]), all(tree[i*2 + 1]), tree[i].begin());
    }
}

int query(int node, int nodeL, int nodeR, int L, int R, int k)
{
    if(nodeR < L || R < nodeL) return 0;
    if(L <= nodeL && R >= nodeR)  return upper_bound(all(tree[node]), k) - tree[node].begin();

    return query(node*2, nodeL, (nodeL + nodeR) / 2, L, R, k) + query(node*2 + 1, (nodeL + nodeR) / 2 + 1, nodeR,L, R, k);
}

int main()
{
    fastio;
    cin >> n >> m;
    while(sz < n) sz <<= 1;
    tree.resize(sz * 2);

    for(int i = 0;i<n;i++)
    {
        int x; cin >> x;
        tree[sz+i].push_back(x);
    }

    build();

    while(m--)
    {
        int i,j,k;
        int lo = -INT_MAX, hi = INT_MAX;
        cin >> i >> j >> k;
        while(lo + 1 < hi)
        {
            int mid = (lo + hi) / 2;
            if(query(1,1,sz,i,j,mid) < k) lo = mid;
            else hi = mid;
        }
        cout << hi << '\n';
    }
}