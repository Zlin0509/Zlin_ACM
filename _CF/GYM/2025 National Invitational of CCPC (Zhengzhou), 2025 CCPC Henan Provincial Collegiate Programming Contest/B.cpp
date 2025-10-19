//
// Created by Zlin on 2025/10/19.
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

constexpr ll mo = 998244353;

struct Ftree {
private:
    vi t;

public:
    void init(int n) {
        t.assign(n + 1, 0);
    }

    void upd(int i, int v) {
        while (i < t.size()) {
            t[i] += v;
            i += i & -i;
        }
    }

    int qry1(int i) {
        int s = 0;
        while (i > 0) {
            s += t[i];
            i -= i & -i;
        }
        return s;
    }

    int qry2(int l, int r) {
        return qry1(r) - qry1(l - 1);
    }
} t1, t2;

constexpr int N = 5e3 + 10;

ll f[N], g[N];

inline ll qpow(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) res = res * x % mo;
        x = x * x % mo;
        y >>= 1;
    }
    return res;
}

inline void Zlin() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) f[i] = g[i] = 0;
    t1.init(n + 2), t2.init(n + 2);
    int tag = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            int all = t2.qry1(n) - tag;
            for (int j = 1; j <= n; j++) {
                int my = t2.qry2(j, j);
                if (t2.qry1(j) > tag) {
                    if (!tag) g[j] = my % mo * qpow(all, mo - 2) % mo;
                    else
                        g[j] = (f[j - 1] * my % mo * qpow(all, mo - 2) % mo
                                + f[j] * (my - tag) % mo * qpow(all, mo - 2) % mo) % mo;
                }
                f[j] = (f[j] + f[j - 1]) % mo;
            }
            for (int j = 1; j <= n; j++) f[j] = g[j], g[j] = 0;

            ++tag;
        } else t2.upd(a[i], 1);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans = (ans + f[i]) % mo;
    cout << ans << endl;
}

/*
1
7
1 2 2 2 -1 -1 -1
 */

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    // cout << (3 * qpow(4, mo - 2) % mo) << endl;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
