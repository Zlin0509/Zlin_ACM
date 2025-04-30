//
// Created by 27682 on 2025/4/21.
//
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

constexpr int N = 55;
const ull mask = mt19937_64(time(nullptr))();

inline ull shift(ull x) {
    x ^= mask;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    x ^= mask;
    return x;
}

ull ha[N];
pair<ull, ull> val[N];
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

inline void dfs(int u, int fa) {
    siz[u] = 1;
    ha[u] = 1;
    for (int v: e[u]) {
        if (v == fa) continue;
        dfs(v, u);
        ha[u] += shift(ha[v]);
    }
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
    dfs(rt[0], rt[0]);
    val[id].first = ha[rt[0]];
    if (rt.size() >= 2) {
        dfs(rt[1], rt[1]);
        val[id].second = ha[rt[1]];
    } else val[id].second = 0;
    if (val[id].first > val[id].second) swap(val[id].first, val[id].second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
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