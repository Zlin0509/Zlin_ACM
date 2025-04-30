//
// Created by 27682 on 2025/4/21.
//

#include "bits/stdc++.h"

#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ull mask = mt19937_64(time(nullptr))();

inline ull shift(ull x) {
    x ^= mask;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    x ^= mask;
    return x;
}

constexpr int N = 2e5 + 10;

int n;
ull ha[N];
vi e[N];

inline void dfs(int u, int fa) {
    ha[u] = 1;
    for (int v: e[u]) {
        if (v == fa) continue;
        dfs(v, u);
        ha[u] += shift(ha[v]);
    }
}

bool cal(int u, int fa) {
    int cnt = 0;
    set<ull> all;
    unordered_map<ull, int> mp;
    for (int v: e[u]) {
        if (v == fa) continue;
        ++mp[ha[v]];
        all.insert(ha[v]);
        ++cnt;
    }
    if (cnt & 1) {
        ull tag = 0;
        for (ull it: all) {
            if (mp[it] & 1) {
                if (tag) return false;
                tag = it;
            }
        }
        for (int v: e[u]) {
            if (v == fa || ha[v] != tag) continue;
            return cal(v, u);
        }
    } else {
        for (ull it: all) if (mp[it] & 1) return false;
        return true;
    }
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ha[i] = 0;
        e[i].clear();
    }
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if (n == 1) {
        cout << "YES" << endl;
        return;
    }
    dfs(1, 0);
    cout << (cal(1, 0) ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
