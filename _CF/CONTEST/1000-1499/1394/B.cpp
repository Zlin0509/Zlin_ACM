//
// Created by 27682 on 2025/6/25.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

// all = 362880

constexpr int N = 2e5 + 10;
constexpr ll p = 11451431, mo = 9982442531;

int n, m, k;
vi e[N], in[10][10], out[10][10];
vector<pii> edge(N);
ll inh[10][10], outh[10][10], fac[N];
pair<ll, ll> base;

int ans = 0;

inline void dfs(int i, pair<ll, ll> res) {
    if (i == k + 1) {
        ans += res == base;
        return;
    }
    for (int j = 1; j <= i; j++) dfs(i + 1, {(res.first + inh[i][j]) % mo, (res.second + outh[i][j]) % mo});
}

inline void Zlin() {
    cin >> n >> m >> k;
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        e[u].push_back(w);
        edge[w] = {u, v};
    }
    for (int i = 1; i <= n; i++) {
        sort(e[i].begin(), e[i].end());
        for (int j = 0; j < e[i].size(); j++) {
            in[e[i].size()][j + 1].push_back(edge[e[i][j]].second);
            out[e[i].size()][j + 1].push_back(edge[e[i][j]].first);
        }
    }
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * p % mo;
        base.first = (base.first + fac[i] * i) % mo;
        base.second = (base.second + fac[i] * i) % mo;
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= i; j++) {
            for (int id: in[i][j]) inh[i][j] = (inh[i][j] + fac[id] * id) % mo;
            for (int id: out[i][j]) outh[i][j] = (outh[i][j] + fac[id] * id) % mo;
        }
    }
    dfs(1, {0, 0});
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
