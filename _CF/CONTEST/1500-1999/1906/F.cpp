//
// Created by 27682 on 2025/3/19.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct STree
{
private:
    struct node
    {
        int l, r;
        ll val, tag;
        ll pre, suf;

        friend node operator +(const node& a, const node& b)
        {
            node res;
            res.l = min(a.l, b.l);
            res.r = max(a.r, b.r);
            res.val = a.val + b.val;
            res.pre = max(a.pre, a.val + b.pre);
            res.suf = max(b.suf, b.val + a.suf);
            res.tag = max({a.tag, b.tag, a.suf + b.pre});
            return res;
        }
    };

    vector<node> t;

    void pushup(int i)
    {
        t[i] = t[i << 1] + t[i << 1 | 1];
    }

    void build(int i, int l, int r)
    {
        t[i].l = l, t[i].r = r;
        if (l == r)
        {
            t[i].val = t[i].tag = t[i].pre = t[i].suf = 0;
            return;
        }
        int mid = l + r >> 1;
        build(i << 1, l, mid);
        build(i << 1 | 1, mid + 1, r);
        pushup(i);
    }

public:
    void init(int n)
    {
        t.assign(n << 2, {});
        build(1, 1, n);
    }

    void update(int i, int id, int val)
    {
        int lx = t[i].l, rx = t[i].r;
        if (rx < id || lx > id)
            return;
        if (lx == id && rx == id)
        {
            t[i].val += val;
            t[i].tag += val;
            t[i].pre += val;
            t[i].suf += val;
            return;
        }
        update(i << 1, id, val);
        update(i << 1 | 1, id, val);
        pushup(i);
    }

    node query(int i, int l, int r)
    {
        int lx = t[i].l, rx = t[i].r;
        if (lx == l && rx == r)
            return t[i];
        int mid = lx + rx >> 1;
        if (mid >= r)
            return query(i << 1, l, r);
        if (mid + 1 <= l)
            return query(i << 1 | 1, l, r);
        return query(i << 1, l, mid) + query(i << 1 | 1, mid + 1, r);
    }
} t;

int n, m, q;
vector<vector<pii>> op;
vll ans;

struct query
{
    int l, r, id;
};

vector<vector<query>> qry;

inline void Zlin()
{
    cin >> n >> m;
    op.assign(n + 2, vector<pii>());
    for (int i = 1, l, r, x; i <= m; i++)
    {
        cin >> l >> r >> x;
        op[l].push_back({x, i});
        op[r + 1].push_back({-x, i});
    }
    cin >> q;
    ans.assign(q, 0);
    qry.assign(n + 1, vector<query>());
    for (int i = 0, k, s, t; i < q; i++)
    {
        cin >> k >> s >> t;
        qry[k].push_back({s, t, i});
    }
    t.init(m);
    for (int i = 1; i <= n; i++)
    {
        for (auto [val, id] : op[i])
            t.update(1, id, val);
        for (auto [l, r, id] : qry[i])
            ans[id] = t.query(1, l, r).tag;
    }
    for (ll it : ans)
        cout << it << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
