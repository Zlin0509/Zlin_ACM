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

struct PStree
{
private:
    struct node
    {
        int l, r;
        int val;
        node* ls = nullptr;
        node* rs = nullptr;
    };

    vector<node*> t;

    void pushup(node& t)
    {
        t.val = t.ls->val + t.rs->val;
    }

    void build(node& t, int l, int r)
    {
        t.l = l, t.r = r;
        if (l == r)
        {
            t.val = 0;
            return;
        }
        t.ls = new node();
        t.rs = new node();
        int mid = l + r >> 1;
        build(*t.ls, l, mid);
        build(*t.rs, mid + 1, r);
        pushup(t);
    }

    void update(const node& bef, node& now, int k, int val)
    {
        now.l = bef.l, now.r = bef.r;
        if (now.l == k && k == now.r)
        {
            now.val = bef.val + val;
            return;
        }
        int mid = now.l + now.r >> 1;
        if (k <= mid)
        {
            now.ls = new node();
            update(*bef.ls, *now.ls, k, val);
            now.rs = bef.rs;
        }
        else
        {
            now.ls = bef.ls;
            now.rs = new node();
            update(*bef.rs, *now.rs, k, val);
        }
        pushup(now);
    }

    int query(const node* now, int k)
    {
        if (now->l == now->r)
            return now->l;
        if (now->ls->val >= k)
            return query(now->ls, k);
        return query(now->rs, k - now->ls->val);
    }

    int query1(const node* bef, const node* now, int k)
    {
        if (now->l == now->r)
            return now->l;
        if (now->ls->val - bef->ls->val >= k)
            return query1(bef->ls, now->ls, k);
        return query1(bef->rs, now->rs, k - now->ls->val + bef->ls->val);
    }

public:
    void init(int n, int val)
    {
        t.resize(n + 1, nullptr);
        t[0] = new node();
        build(*t[0], 1, val);
    }

    void upd(int bef, int now, int k, int val)
    {
        t[now] = new node();
        update(*t[bef], *t[now], k, val);
    }

    int qry(int now, int k)
    {
        return query(t[now], k);
    }

    int qry1(int bef, int now, int k)
    {
        return query1(t[bef - 1], t[now], k);
    }
} t;

inline void Zlin()
{
    int n, m;
    cin >> n >> m;
    vi a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], b[i] = a[i];
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    t.init(n, b.size());
    for (int i = 0; i < n; i++)
    {
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        t.upd(i, i + 1, a[i], 1);
    }
    while (m--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        cout << b[t.qry1(l, r, k) - 1] << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
