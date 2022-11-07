#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

#define all(v) v.begin(), v.end()

int n, sz = 1;
vector<vector<int>> tree;

void build()
{
    for(int i = sz - 1; i>0;i--) // 7 6 5 4 3 2 1
    {
        tree[i].resize(tree[i*2].size() + tree[i*2 + 1].size());
        merge(all(tree[i*2]), all(tree[i*2 +1]), tree[i].begin());
    }
}

int query(int node, int nodeL, int nodeR, int L, int R, int k)
{   
    if(R < nodeL || nodeR < L) return 0;
    if(L <= nodeL &&  nodeR <= R) return tree[node].end() -  upper_bound(all(tree[node]), k);   
    return query(node*2, nodeL, (nodeL + nodeR) / 2, L, R, k) + query(node*2 + 1, (nodeL+nodeR) / 2 + 1, nodeR, L, R, k);
}

int main()
{
    fastio;
    cin >> n; // n == 5
    while(sz < n) sz <<= 1; // sz == 8
    tree.resize(sz * 2); // tree.size() == 16
    for(int i = 0;i<n;i++)
    {
        int x; cin >> x;
        tree[sz+i].push_back(x); // tree[8], tree[9], tree[10], tree[11], tree[12] 
    }

    build();

   int m, last_ans = 0;
   cin >> m;
   while(m--)
   {
        int a, b, c; 
        cin >> a >> b >> c;
        last_ans = query(1, 1, sz, a ^ last_ans, b ^ last_ans, c ^ last_ans);
        cout << last_ans << '\n';
   }
}