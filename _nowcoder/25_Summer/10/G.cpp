//
// Created by Zlin on 2025/8/14.
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

constexpr int N = 1e5 + 10;
constexpr ll mo = 1e9;

int n, m, q;
ll a[N], ans = 0, base;

struct SplayStep {
    struct Node {
        int ch[2], fa;
        long long val;
        int idx; // 原下标
        long long sum[10]; // m <= 10 为例
        int sz;
    };

    vector<Node> t;
    int root, m;

    SplayStep(int n, int m) : t(n + 1), root(0), m(m) {
    }

    int newnode(long long v, int id) {
        static int tot = 0;
        ++tot;
        t[tot].val = v;
        t[tot].idx = id;
        t[tot].fa = t[tot].ch[0] = t[tot].ch[1] = 0;
        memset(t[tot].sum, 0, sizeof(t[tot].sum));
        t[tot].sum[id % m] = v;
        t[tot].sz = 1;
        return tot;
    }

    void push_up(int x) {
        t[x].sz = 1;
        memset(t[x].sum, 0, sizeof(t[x].sum));
        if (t[x].ch[0]) {
            t[x].sz += t[t[x].ch[0]].sz;
            for (int i = 0; i < m; i++) t[x].sum[i] += t[t[x].ch[0]].sum[i];
        }
        t[x].sum[t[x].idx % m] += t[x].val;
        if (t[x].ch[1]) {
            t[x].sz += t[t[x].ch[1]].sz;
            for (int i = 0; i < m; i++) t[x].sum[i] += t[t[x].ch[1]].sum[i];
        }
    }

    void rotate(int x) {
        int y = t[x].fa, z = t[y].fa;
        int k = (t[y].ch[1] == x);
        t[y].ch[k] = t[x].ch[k ^ 1];
        if (t[x].ch[k ^ 1]) t[t[x].ch[k ^ 1]].fa = y;
        t[x].ch[k ^ 1] = y;
        t[y].fa = x;
        t[x].fa = z;
        if (z) t[z].ch[t[z].ch[1] == y] = x;
        push_up(y);
        push_up(x);
    }

    void splay(int x, int goal = 0) {
        while (t[x].fa != goal) {
            int y = t[x].fa, z = t[y].fa;
            if (z != goal) {
                if ((t[y].ch[0] == x) ^ (t[z].ch[0] == y)) rotate(x);
                else rotate(y);
            }
            rotate(x);
        }
        if (!goal) root = x;
    }

    int kth(int k) {
        int x = root;
        while (1) {
            int lsz = t[x].ch[0] ? t[t[x].ch[0]].sz : 0;
            if (k <= lsz) x = t[x].ch[0];
            else if (k == lsz + 1) return x;
            else k -= lsz + 1, x = t[x].ch[1];
        }
    }

    void insert(long long v, int id) {
        if (!root) {
            root = newnode(v, id);
            return;
        }
        int x = root, f = 0;
        while (x) {
            f = x;
            if (v < t[x].val || (v == t[x].val && id < t[x].idx)) x = t[x].ch[0];
            else x = t[x].ch[1];
        }
        int now = newnode(v, id);
        t[now].fa = f;
        if (v < t[f].val || (v == t[f].val && id < t[f].idx)) t[f].ch[0] = now;
        else t[f].ch[1] = now;
        splay(now);
    }

    void update_val(int id, long long newv) {
        // 找到原下标为 id 的节点
        int x = root;
        while (t[x].idx != id) {
            if (newv < t[x].val || (newv == t[x].val && id < t[x].idx)) x = t[x].ch[0];
            else x = t[x].ch[1];
        }
        splay(x);
        t[x].val = newv;
        memset(t[x].sum, 0, sizeof(t[x].sum));
        t[x].sum[id % m] = newv;
        push_up(x);
    }

    long long query_kth_prefix(int k) {
        int x = kth(k);
        splay(x);
        long long res = 0;
        if (t[x].ch[0]) res += t[t[x].ch[0]].sum[t[x].idx % m];
        res += t[x].sum[t[x].idx % m] - (t[x].ch[0] ? t[t[x].ch[0]].sum[t[x].idx % m] : 0);
        return res;
    }
};

inline void Zlin() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    SplayStep sp(n, m);
    for (int i = 1; i <= n; i++) sp.insert(a[i], i);
    while (q--) {
        ll x, y, z;
        cin >> x >> y >> z;
        x = 1 + (x + ans) % n, y = 1 + (y + ans) % mo, z = 1 + (z + ans) % n;
        sp.update_val(x, y);
        ans = sp.query_kth_prefix(z);
        cout << ans << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
