//
// Created by Zlin on 2025/1/26.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
vector<string> words;

const int MAXN = 1e5 + 5;

#define lowbit(x) (x & (-x))
int t[MAXN];

inline void add(int i, int k)
{
    for (; i <= n; i += lowbit(i))
        t[i] += k;
    return;
}


inline int ask(int l, int r)
{
    int sum = 0;
    for (; r; r -= lowbit(r))
        sum += t[r];
    --l;
    for (; l; l -= lowbit(l))
        sum -= t[l];
    return sum;
}

struct TrieNode
{
    unordered_map<char, TrieNode*> children;
    int depth, belong = 0; // 表示当前节点的深度（从根节点开始）

    TrieNode() : depth(0)
    {
    }
};

class Trie
{
public:
    TrieNode* root;
    int count;

    Trie()
    {
        count = 0;
        root = new TrieNode();
    }

    void insert(const string& word, const int& tag)
    {
        TrieNode* node = root;
        for (char c : word)
        {
            if (!node->children.count(c))
            {
                ++count;
                node->children[c] = new TrieNode();
                node->children[c]->depth = node->depth + 1;
            }
            node = node->children[c];
            if (node->belong)
                add(node->belong, -1);
            node->belong = tag;
            add(node->belong, 1);
        }
    }
} tt;

int f[100010][22];

inline void ST_prework()
{
    for (int i = 1; i <= n; i++)
        f[i][0] = words[i].length();
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

inline void Zlin()
{
    cin >> n >> m;
    words.assign(n + 1, "");
    for (int i = 1; i <= n; i++)
    {
        cin >> words[i];
        tt.insert(words[i], i);
    }
    ST_prework();
    vector<vector<pii>> op(n + 1);
    vi ans(m);
    for (int i = 0, l, r; i < m; i++)
    {
        cin >> l >> r;
        op[r].emplace_back(l, i);
    }
    for (int r = 1; r <= n; r++)
    {
        tt.insert(words[r], r);
        for (auto [l,id] : op[r])
            ans[id] = ask(l, r) * 2 - ST_query(l, r);
    }
    for (auto it : ans)
        cout << it << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
