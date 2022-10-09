#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

class TrieNode
{
public:
    bool valid;
    int child[26];
    TrieNode()
    {
        valid = false;
        for (int i = 0; i < 26; i++)
            child[i] = -1;
    }
};

class Trie
{
private:
    vector<TrieNode> trie;

    int _newNode()
    {
        TrieNode tmp;
        trie.push_back(tmp);
        return trie.size() - 1;
    }

    void _add(string &str, int node, int idx)
    {
        if (idx == str.size())
        {
            trie[node].valid = true;

            return;
        }

        int c = str[idx] - 'a';
        if (trie[node].child[c] == -1)
        {
            int nxt = _newNode();
            trie[node].child[c] = nxt;
        }

        _add(str, trie[node].child[c], idx + 1);
    }

    bool _find(string &str)
    {
        int now = 0;
        for (int i = 0; i < str.size(); i++)
        {
            int c = str[i] - 'a';
            if (trie[now].child[c] == -1)
                return false;
            now = trie[now].child[c];
        }

        return true;
    }

public:
    Trie()
    {
        _newNode();
    }

    void add(string &str)
    {
        _add(str, 0, 0);
    }

    bool find(string &str)
    {
        return _find(str);
    }
};

int main()
{
    fastio;
    int n, m, cnt = 0;
    Trie tr;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        tr.add(str);
    }

    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        if (tr.find(str))
            cnt++;
    }

    cout << cnt;
}