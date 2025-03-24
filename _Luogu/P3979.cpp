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
        int val = 0;
        node* nex;
        node* next[26];
    };

    node* root;

public:
    AC_auto() { root = new node(); }

    // 多测注意内存开销
    // ~AC_auto()
    // {
    //     unordered_set<node*> visited;
    //     queue<node*> s;
    //     s.push(root);
    //     while (!s.empty())
    //     {
    //         node* cur = s.front();
    //         s.pop();
    //         if (visited.count(cur))
    //             continue;
    //         visited.insert(cur);
    //         for (int i = 0; i < 26; i++)
    //         {
    //             if (cur->next[i] != nullptr && !visited.count(cur->next[i]))
    //                 s.push(cur->next[i]);
    //         }
    //         delete cur;
    //     }
    // }

    void ins(const string& s, int val)
    {
        node* now = root;
        for (char it : s)
        {
            if (now->next[it - 'a'] == nullptr)
                now->next[it - 'a'] = new node();
            now = now->next[it - 'a'];
        }
        now->val += val;
    }

    void build()
    {
        queue<node*> q;
        root->nex = root;
        for (int i = 0; i < 26; i++)
        {
            if (root->next[i] != nullptr)
            {
                root->next[i]->nex = root;
                q.push(root->next[i]);
            }
            else root->next[i] = root;
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

    int qry(const string& s)
    {
        int res = 0;
        node* now = root;
        for (char it : s)
        {
            now = now->next[it - 'a'];
            for (node* cal = now; cal != root && ~cal->val; cal = cal->nex)
                res += cal->val;
        }
        return res;
    }
} t;

inline void Zlin()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
