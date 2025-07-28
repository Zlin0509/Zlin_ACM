//
// Created by Zlin on 2025/7/28.
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

constexpr int N = 310;
constexpr ll mo = 998244353;

inline ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return res;
}

int n, dep, tag[N], in[N];
string s;
vi e[N];
ll val[N][N], sum[N];

inline void dfs(int u, int fa) {
    ll inv = qpow(e[u].size(), mo - 2);
    for (int i = 0; i <= dep; i++) val[u][i] = 0;

    if (fa && tag[dep] && e[fa].size() > 1) val[u][0] = (sum[fa] - u) * qpow(e[fa].size() - 1, mo - 2) % mo;
    else val[u][0] = u;

    if (!inv) for (int i = 1; i <= dep; i++) val[u][i] = val[u][i - 1];
    else {
        for (int v: e[u]) {
            dfs(v, u);
            for (int i = 1; i <= dep; i++) val[u][i] = (val[u][i] + val[v][i - 1] * inv % mo) % mo;
        }
    }
}

inline void Zlin() {
    cin >> n >> s;
    dep = 0, tag[dep] = 0;
    for (char it: s) {
        if (it == 'D') tag[++dep] = 0;
        else if (it == 'L') --tag[dep];
        else ++tag[dep];
        tag[dep] = max(0, tag[dep]);
    }
    for (int i = 1; i <= n; i++) {
        e[i].clear();
        sum[i] = in[i] = 0;
    }
    for (int i = 1, k; i <= n; i++) {
        cin >> k;
        for (int j = 1, u; j <= k; j++) {
            cin >> u;
            e[i].emplace_back(u);
            ++in[u];
            sum[i] += u;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            dfs(i, 0);
            cout << val[i][dep] << endl;
            break;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
