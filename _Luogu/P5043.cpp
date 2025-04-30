//
// Created by 27682 on 2025/4/21.
//
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

constexpr int N = 55;
constexpr ll p = 19491001, mo = 1019260817;

ll ha[N], fac[N];
pll val[N];
vi e[N], rt;
int n, m, siz[N];

inline void findrt(int u, int fa) {
    siz[u] = 1;
    int maxn = 0;
    for (int v: e[u]) {
        if (v == fa) continue;
        findrt(v, u);
        siz[u] += siz[v];
        maxn = max(maxn, siz[v]);
    }
    maxn = max(maxn, n - siz[u]);
    if (maxn <= n / 2) rt.push_back(u);
}

inline ll dfs(int u, int fa, int dep) {
    vector<pll> have;
    siz[u] = 1;
    for (int v: e[u]) {
        if (v == fa) continue;
        have.push_back({dfs(v, u, dep + 1), siz[v]});
    }
    sort(have.begin(), have.end());
    ha[u] = dep * fac[siz[u]] % mo;
    for (auto [has, si]: have) {
        siz[u] += si;
        ha[u] = (ha[u] + has * fac[siz[u]] % mo) % mo;
    }
    return ha[u];
}

inline void Zlin(int id) {
    cin >> n;
    rt.clear();
    for (int i = 0; i <= n; i++) e[i].clear();
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        if (x) {
            e[x].push_back(i);
            e[i].push_back(x);
        }
    }
    findrt(1, 1);
    vll res;
    for (int it: rt) res.push_back(dfs(it, it, 1));
    val[id] = {res[0], res.size() >= 2 ? res[1] : 0};
    if (val[id].first > val[id].second) swap(val[id].first, val[id].second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * p % mo;
    cin >> m;
    for (int i = 1; i <= m; i++) Zlin(i);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            if (val[i] == val[j]) {
                cout << j << endl;
                break;
            }
        }
    }
}