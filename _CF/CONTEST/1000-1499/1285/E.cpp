//
// Created by Zlin on 2025/6/23.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int N = 2e5 + 10;

vi e[N];

int dfn[N], low[N], tot;
int cut[N];

inline void tarjan(int u, int fa) {
    int child = 0;
    dfn[u] = low[u] = ++tot;
    for (int v: e[u]) {
        if (!dfn[v]) {
            ++child;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (fa != -1 && low[v] >= dfn[u]) cut[u]++;
        } else if (v != fa) low[u] = min(low[u], dfn[v]);
    }
    if (fa == -1 && child >= 2) cut[u] = child - 1;
    if (fa == -1 && child == 0) cut[u] = -1;
}

inline void Zlin() {
    int n;
    cin >> n;
    vi have;
    vector<pii> a(n);
    tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        have.push_back(a[i].first);
        have.push_back(a[i].second);
        e[i].clear();
        cut[i] = dfn[i] = low[i] = 0;
    }
    sort(have.begin(), have.end());
    have.erase(unique(have.begin(), have.end()), have.end());
    for (auto &[l, r]: a) {
        l = lower_bound(have.begin(), have.end(), l) - have.begin();
        r = lower_bound(have.begin(), have.end(), r) - have.begin();
    }
    sort(a.begin(), a.end(), [](const pii &a, const pii &b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });
    set<pii> st;
    for (int i = 0; i < n; i++) {
        auto [l, r] = a[i];
        auto it = st.lower_bound({l, 0});
        if (it != st.end()) {
            e[it->second].push_back(i);
            e[i].push_back(it->second);
            if (next(it) != st.end()) {
                e[next(it)->second].push_back(i);
                e[i].push_back(next(it)->second);
            }
        }
        st.insert({r, i});
    }
    int cnt = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (!dfn[i]) {
            tarjan(i, -1);
            ++cnt;
        }
    }
    for (int u = 0; u < n; u++) ans = max(ans, cnt + cut[u]);
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
