//
// Created by Zlin on 2025/3/24.
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

struct AC_auto
{
private:
    struct node
    {
        int val = 0, id = -1;
        node* nex = nullptr;
        node* next[26] = {nullptr};
    };

    static const int N = 2e5 + 5;
    node pool[N];
    int tot = 0;

    node* alloc()
    {
        pool[tot] = node();
        return &pool[tot++];
    }

    node* root;

public:
    void init()
    {
        tot = 0;
        root = alloc();
    }

    void ins(const string& s, int val, int id)
    {
        node* now = root;
        for (char it : s)
        {
            if (now->next[it - 'a'] == nullptr)
                now->next[it - 'a'] = alloc();
            now = now->next[it - 'a'];
        }
        now->val += val;
        now->id = id;
    }

    void build()
    {
        queue<node*> q;
        root->nex = root;
        for (int i = 0; i < 26; i++)
        {
            if (root->next[i] != nullptr)
                q.push(root->next[i]);
            else
                root->next[i] = root;
            root->next[i]->nex = root;
        }
        while (!q.empty())
        {
            node* now = q.front();
            q.pop();
            for (int i = 0; i < 26; i++)
            {
                if (now->next[i] != nullptr)
                {
                    now->next[i]->nex = now->nex->next[i];
                    q.push(now->next[i]);
                }
                else now->next[i] = now->nex->next[i];
            }
        }
    }

    void qry(const string& s, vi& cnt)
    {
        node* now = root;
        for (char it : s)
        {
            now = now->next[it - 'a'];
            for (node* cal = now; cal != root; cal = cal->nex)
                if (~cal->id)
                    ++cnt[cal->id];
        }
    }
} t;

inline void Zlin(int n)
{
    t.init();
    string s;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i], t.ins(v[i], 1, i);
    t.build();
    cin >> s;
    vi cnt(n);
    t.qry(s, cnt);
    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, cnt[i]);
    cout << res << endl;
    for (int i = 0; i < n; i++)
        if (res == cnt[i])
            cout << v[i] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (cin >> ttt)
    {
        if (ttt == 0)
            break;
        Zlin(ttt);
    }
    return 0;
}
