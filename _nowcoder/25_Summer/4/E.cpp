//
// Created by 27682 on 2025/7/24.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 5e5 + 10;
constexpr int mo = 1 << 25;

int n, q, a[N];

int w[N];
vi e[N];

namespace Seg {
    struct Node {
        int val;
    } t[N << 2];

    Node operator+(Node a, Node b) {
        Node res;
        res.val = max(a.val, b.val);
        return res;
    }

    inline void update(int i) {
        t[i] = t[i << 1] + t[i << 1 | 1];
    }

    inline void build(int i, int l, int r) {
        if (l == r) {
            t[i].val = w[l];
            return;
        }
        int mid = l + r >> 1;
        build(i << 1, l, mid);
        build(i << 1 | 1, mid + 1, r);
        update(i);
    }

    inline void change(int i, int l, int r, int pos, int val) {
        if (l == r) {
            t[i].val = val;
            return;
        }
        int mid = l + r >> 1;
        if (pos <= mid) change(i << 1, l, mid, pos, val);
        else change(i << 1 | 1, mid + 1, r, pos, val);
        update(i);
    }

    inline Node query(int i, int l, int r, int st, int ed) {
        if (r < st || l > ed) return {};
        if (l >= st && r <= ed) return t[i];
        int mid = l + r >> 1;
        return query(i << 1, l, mid, st, ed) + query(i << 1 | 1, mid + 1, r, st, ed);
    }
}

namespace HLD {
    int dfn[N], tot;
    int dep[N], len[N], son[N], siz[N], fa[N], top[N];

    inline void dfs1(int u) {
        siz[u] = len[u] = 1;
        dep[u] = dep[fa[u]] + 1;
        for (int v: e[u]) {
            if (v == fa[u]) continue;
            fa[v] = u;
            dfs1(v);
            len[u] = max(len[u], len[v] + 1);
            siz[u] += siz[v];
            if (siz[v] > siz[son[u]]) son[u] = v;
        }
    }

    inline void dfs2(int u, int s) {
        dfn[u] = ++tot;
        w[dfn[u]] = a[u];
        top[u] = s;
        if (son[u]) dfs2(son[u], s);
        for (int v: e[u]) {
            if (v == fa[u] || v == son[u]) continue;
            dfs2(v, v);
        }
    }

    inline void init(int n) {
        tot = 0;
        for (int i = 1; i <= n; i++) {
            dfn[i] = len[i] = dep[i] = son[i] = siz[i] = top[i] = 0;
        }
        dfs1(1);
        dfs2(1, 1);
        Seg::build(1, 1, n);
    }

    inline void change(int pos, int val) {
        w[dfn[pos]] = val;
        Seg::change(1, 1, n, dfn[pos], val);
    }

    inline vector<pii> add(int st, int ed) {
        vector<pii> res;
        int l = st, r = ed;
        while (l <= ed && res.size() <= 25) {
            int lx = l, mid;
            if (w[l] == 1) {
                while (l < r) {
                    mid = l + r + 1 >> 1;
                    if (Seg::query(1, 1, n, lx, mid).val == 1) l = mid;
                    else r = mid - 1;
                }
            }
            res.emplace_back(w[l], l - lx + 1);
            l = l + 1, r = ed;
        }
        return res;
    }

    inline bool query(int l, int r) {
        vector<pii> res, vl, vr, tmp;
        while (top[l] != top[r]) {
            if (dep[top[l]] > dep[top[r]]) {
                tmp = add(dfn[top[l]], dfn[l]);
                while (!tmp.empty()) {
                    vl.emplace_back(tmp.back());
                    tmp.pop_back();
                }
                if (vl.size() + vr.size() > 100) return false;
                l = fa[top[l]];
            } else {
                tmp = add(dfn[top[r]], dfn[r]);
                reverse(tmp.begin(), tmp.end());
                while (!tmp.empty()) {
                    vr.emplace_back(tmp.back());
                    tmp.pop_back();
                }
                if (vl.size() + vr.size() > 100) return false;
                r = fa[top[r]];
            }
        }
        if (dep[l] > dep[r]) {
            tmp = add(dfn[r], dfn[l]);
            while (!tmp.empty()) {
                vl.emplace_back(tmp.back());
                tmp.pop_back();
            }
        } else {
            tmp = add(dfn[l], dfn[r]);
            reverse(tmp.begin(), tmp.end());
            while (!tmp.empty()) {
                vr.emplace_back(tmp.back());
                tmp.pop_back();
            }
        }
        for (auto [val, cnt]: vl) {
            if (res.empty() || val != 1 || res.back().first != 1) {
                res.emplace_back(val, cnt);
            } else res.back().second += cnt;
        }
        for (auto [val, cnt]: vr) {
            if (res.empty() || val != 1 || res.back().first != 1) {
                res.emplace_back(val, cnt);
            } else res.back().second += cnt;
        }
        if (res.size() > 30) return false;
        for (auto &[val, cnt]: res) cnt = min(cnt, 24);
        int f = 0, g = 0;
        if (res[0].first == 1) {
            for (int j = 1; j <= res[0].second; j++) {
                f |= 1 << j;
            }
        } else f |= 1 << res[0].first;
        for (int i = 1; i < res.size(); i++) {
            if (res[i].first == 1) {
                for (int j = 0; j <= res[i].second; j++) g |= (f << j) % mo;
            } else {
                for (int j = 1; j <= 24; j++) {
                    if (f >> j & 1) {
                        if (j + res[i].first <= 24) g |= 1 << j + res[i].first;
                        if (1ll * j * res[i].first <= 24) g |= 1 << j * res[i].first;
                    }
                }
            }
            f = g, g = 0;
        }
        return f >> 24 & 1;
    }
}

inline void Zlin() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    HLD::init(n);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            cout << (HLD::query(l, r) ? 1 : 0) << endl;
        } else {
            int x, d;
            cin >> x >> d;
            HLD::change(x, d);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
