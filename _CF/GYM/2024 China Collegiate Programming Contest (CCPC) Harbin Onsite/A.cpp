//
// Created by Zlin on 2025/8/3.
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

constexpr int N = 1e6 + 10;

int l, r, cnt = 0;
int base = 0, nxt[N], mx = 1;
vector<pii> ans[N];
map<pii, int> dfn;
int dfn1[N];

inline bool dfs(int base, int dep) {
    if (dep < 0) return base >= l && base <= r;
    if (base > r || base + (1 << dep + 1) - 1 < l) return false;
    dfn[{base, dep}] = ++cnt;
    if (base + (1 << dep + 1) - 1 <= r && base >= l) {
        mx = max(mx, dep + 1);
        nxt[dfn[{base, dep}]] = 6 + dep;
        return true;
    }
    bool check = false;
    if (dfs(base + (1 << dep), dep - 1)) {
        if (dep) nxt[dfn[{base, dep}]] |= 1;
        check = true;
    }
    if (dfs(base, dep - 1)) {
        if (dep) nxt[dfn[{base, dep}]] |= 2;
        check = true;
    }
    return check;
}

inline void work(int base, int dep) {
    if (dep < 0) return;
    int p = dfn[{base, dep}], lp = dfn[{base, dep - 1}], rp = dfn[{base + (1 << dep), dep - 1}];
    if (nxt[p] > 5) {
        ans[p].emplace_back(cnt + nxt[p] - 5, 0);
        ans[p].emplace_back(cnt + nxt[p] - 5, 1);
    } else if (nxt[p] == 3) {
        ans[p].emplace_back(lp, 0);
        work(base, dep - 1);
        ans[p].emplace_back(rp, 1);
        work(base + (1 << dep), dep - 1);
    } else if (nxt[p] == 2) {
        ans[p].emplace_back(lp, 0);
        work(base, dep - 1);
    } else if (nxt[p] == 1) {
        ans[p].emplace_back(rp, 1);
        work(base + (1 << dep), dep - 1);
    } else if (dep == 0) {
        if (base >= l && base <= r) ans[p].emplace_back(cnt + 1, 0);
        if (base + 1 >= l && base + 1 <= r) ans[p].emplace_back(cnt + 1, 1);
    }
}

vector<pii> g[N];
int cc = 0;

inline void dfs1(int u, int tag) {
    if (dfn1[u]) return;
    for (auto [v, val]: ans[u]) tag |= val;
    if (tag && !dfn1[u]) dfn1[u] = ++cc;
    for (auto [v, val]: ans[u]) {
        dfs1(v, tag);
        if (tag) g[dfn1[u]].emplace_back(dfn1[v], val);
    }
}

inline void Zlin() {
    cin >> l >> r;
    cnt = 0, mx = 1;
    dfs(0, 21);
    work(0, 21);
    for (int i = cnt + mx; i > cnt + 1; i--) {
        ans[i].emplace_back(i - 1, 0);
        ans[i].emplace_back(i - 1, 1);
    }
    dfs1(1, 0);
    cout << cc << endl;
    for (int i = 1; i <= cc; i++) {
        cout << g[i].size() << ' ';
        for (auto [x, y]: g[i]) cout << x << ' ' << y << ' ';
        cout << endl;
    }
    if (cc > 100) while (1);
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    // ttt = 10000;
    while (ttt--) Zlin();
    return 0;
}
