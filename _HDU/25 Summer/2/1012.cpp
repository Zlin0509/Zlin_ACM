//
// Created by 27682 on 2025/7/21.
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

struct LinearBasis {
    ll basis[62];
    bool zero;

    void init() {
        memset(basis, 0, sizeof(basis));
        zero = false;
    }

    bool insert(ll x) {
        for (int i = 60; ~i; i--) {
            if (x >> i & 1) {
                if (!basis[i]) {
                    basis[i] = x;
                    return true;
                }
                x ^= basis[i];
            }
        }
        zero = true;
        return false;
    }

    // 查询异或最大值
    ll query_max() {
        ll res = 0;
        for (int i = 60; ~i; i--)if ((res ^ basis[i]) > res) res ^= basis[i];
        return res;
    }
};

int n;
ll a[55], ans;

inline void dfs(int idx, LinearBasis base) {
    if (idx > n) {
        ans = max(ans, base.query_max());
        return;
    }
    base.insert(a[idx]);
    dfs(idx + 2, base);
    dfs(idx + 3, base);
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ans = 0;
    dfs(1, LinearBasis());
    dfs(2, LinearBasis());
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
