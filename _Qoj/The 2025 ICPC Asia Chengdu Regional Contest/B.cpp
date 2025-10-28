//
// Created by Zlin on 2025/10/28.
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

constexpr int N = 1 << 6;
constexpr ll INF = 1e12;

inline vector<vll> mul(vector<vll> a, vector<vll> b) {
    int n = a.size();
    vector res(n, vll(n, -INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] = max(res[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    return res;
}

inline ll qpow(vector<vll> a, int b) {
    int n = a.size();
    vector res(n, vll(n, -INF));
    res[0][0] = 0;
    while (b) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, res[0][i]);
    return ans;
}

int n, m, k, R, a[10], b[10], c[10];

inline void Zlin() {
    cin >> n >> m >> k >> R;
    for (int i = 0; i < n; i++) cin >> a[i] >> c[i];
    vector mp(1 << n, vll(1 << n, -INF));
    for (int i = 0; i < 1 << n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) b[j] = c[j] + k;
            else b[j] = c[j];
        }
        for (int j = 0; j < 1 << n; j++) {
            int sum = 0, res = 0;
            for (int q = 0; q < n; q++) {
                if (j >> q & 1) {
                    sum += b[q];
                    res += a[q];
                }
            }
            if (sum <= m) mp[i][j] = res;
        }
    }
    cout << qpow(mp, R) << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
