#include "bits/stdc++.h"
using namespace std;

struct TrieNode
{
    unordered_map<char, TrieNode*> children;
    int depth; // 表示当前节点的深度（从根节点开始）
    TrieNode() : depth(0)
    {
    }
};

vector<int> cnt;
unordered_map<pair<char, int>, int> fl, fr;

class Trie
{
public:
    TrieNode* root;
    int totalNodes; // Trie 的节点总数
    int maxDepth; // 最长链的长度

    Trie()
    {
        root = new TrieNode();
        totalNodes = 0;
        maxDepth = 0;
    }

    void insert(const string& word, const int& tag)
    {
        TrieNode* node = root;
        for (char c : word)
        {
            if (!node->children.count(c))
            {
                fl[{c, node->depth + 1}] = min(tag, fl[{c, node->depth + 1}]);
                fr[{c, node->depth + 1}] = max(tag, fr[{c, node->depth + 1}]);
                node->children[c] = new TrieNode();
                node->children[c]->depth = node->depth + 1;
                totalNodes++;
                maxDepth = max(maxDepth, node->children[c]->depth);
            }
            node = node->children[c];
        }
    }
};

int n, m;
int f[100001][22];
vector<string> words;

inline void ST_prework()
{
    for (int i = 1; i <= n; i++)
        f[i][0] = words[i].size();
    int t = log(n) / log(2) + 1;
    for (int j = 1; j < t; j++)
        for (int i = 1; i <= n - (1 << j) + 1; i++)
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

inline int ST_query(int l, int r)
{
    int k = log(r - l + 1) / log(2);
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    words.assign(n, "");
    for (int i = 0; i < n; ++i)
        cin >> words[i];
    ST_prework();


    Trie trie;
    for (int i = 0; i < n; i++)
    {
        trie.insert(words[i], i);
        if (i)
            cnt[i] += cnt[i - 1];
    }
    while (m--)
    {
        int l, r;
        cin >> l >> r;
    }

    return 0;
}
