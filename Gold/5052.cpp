#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

class TrieNode
{
public:
    bool valid;
    int child[10];
    TrieNode()
    {
        valid = false;
        for (int i = 0; i < 10; i++)
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

        int c = str[idx] - '0';
        if (trie[node].child[c] == -1)
        {
            int nxt = _newNode();
            trie[node].child[c] = nxt;
        }

        _add(str, trie[node].child[c], idx + 1);
    }

    bool _exist(string &str)
    {
        int now = 0;
        for (int i = 0; i < str.size(); i++)
        {
            int c = str[i] - '0';
            if (trie[now].child[c] == -1)
                return false;
            now = trie[now].child[c];
        }

        return trie[now].valid;
    }

    bool _isValid(string &str)
    {
        int now = 0;
        for (int i = 0; i < str.size() - 1; i++)
        {
            int c = str[i] - '0';
            now = trie[now].child[c];

            if (trie[now].valid == true)
                return false;
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

    bool exist(string &str)
    {
        return _exist(str);
    }

    bool isValid(string &str)
    {
        return _isValid(str);
    }
};

int main()
{
    fastio;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        bool val = true;
        cin >> n;
        Trie a;
        vector<string> v;
        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            a.add(str);
            v.push_back(str);
        }

        for (auto e : v)
        {
            if (!a.isValid(e))
            {
                cout << "NO\n";
                val = false;
                break;
            }
        }
        
        if(val)
            cout << "YES\n";
    }
}