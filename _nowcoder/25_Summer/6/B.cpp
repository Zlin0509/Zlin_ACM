//
// Created by Zlin on 2025/7/31.
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

constexpr int N = 2e5 + 10;
constexpr ll INF = 1e9 + 1e8;

ll n, y, M, op;
vll a[N];

inline ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a;
        if (res >= INF || a >= INF) return INF;
        a = a * a;
        b >>= 1;
    }
    return res;
}

inline ll cal(ll dif, const vll &s) {
    ll sum = 0;
    for (int i = 0; i < s.size(); i++) {
        sum += s[i] * qpow(dif, s.size() - i - 1);
        if (sum >= INF) return INF;
    }
    return sum;
}

bool check(ll dif) {
    ll s = dif;
    for (int i = 1; i <= n; i++) {
        for (ll it: a[i]) if (it >= s) return false;
        s = cal(s, a[i]);
    }
    return s == y;
}

inline void Zlin() {
    cin >> n >> y >> M;
    op = 0;
    for (int i = 1, l; i <= n; i++) {
        cin >> l;
        a[i].assign(l, 0);
        for (int j = 0; j < l; j++) cin >> a[i][j];
        if (l == 1) op = i;
    }
    if (op) {
        ll l = 0, r = M, mid;
        while (l < r) {
            mid = l + r >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        if (!check(l) || l > M) cout << -1 << ' ' << -1 << endl;
        else cout << l << ' ' << M << endl;
    } else {
        ll l, r, mid, s = y;
        for (int i = n; i; i--) {
            l = 0, r = INF;
            while (l < r) {
                mid = l + r >> 1;
                if (cal(mid, a[i]) >= s) r = mid;
                else l = mid + 1;
            }
            if (cal(l, a[i]) != s) {
                cout << -1 << ' ' << -1 << endl;
                return;
            }
            s = l;
            for (ll it: a[i]) {
                if (it >= s) {
                    cout << -1 << ' ' << -1 << endl;
                    return;
                }
            }
        }
        if (s < 2 || s > M) s = -1;
        cout << s << ' ' << s << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
