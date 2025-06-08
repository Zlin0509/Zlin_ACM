#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;

constexpr ll mo = 1000000007;
constexpr int N = 1e6 + 10;

ll n, val[N], k, inv;
vector<int> e[N];

inline ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return res;
}

inline void dfs(int u, int fa) {
    ll all = 1, cnt = 0;
    for (int v: e[u]) {
        if (v == fa) continue;
        dfs(v, u);
        all = val[v] * inv % mo * all % mo;
        ++cnt;
    }
    if (!cnt) {
        val[u] = k;
    } else {
        ll tmp = k;
        for (int i = 1; i <= min(cnt, k); i++) {
            tmp = tmp * (k - i) % mo;
            ll res = all * qpow(i, cnt - i) % mo * tmp % mo;
            val[u] = (val[u] + res) % mo;
        }
    }
}

inline void Zlin() {
    cin >> n >> k;
    inv = qpow(k, mo - 2);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    cout << val[1] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
