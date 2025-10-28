//
// Created by 27682 on 2025/9/21.
//

#include "bits/stdc++.h"
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long double ldb;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 1005;
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

inline ll re(string s) {
    ll res = 0;
    for (const char &it: s) res = (res * 10 + it - '0') % mo;
    return res;
}

inline ll ask(ll u, ll v) {
    cout << "? " << u << ' ' << v << endl;
    string x, y;
    cin >> x >> y;
    u = re(x), v = re(y);
    return u * qpow(v, mo - 2) % mo;
}

inline void output(ll ans) {
    ans = ans * 2 % mo;
    if (ans & 1) cout << "! " << ans << " " << 2 << endl;
    else cout << "! " << ans / 2 << " " << 1 << endl;
}

inline void Zlin() {
    int n;
    vi tag;
    cin >> n;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        tag.emplace_back(x);
    }
    sort(tag.begin(), tag.end());
    tag.erase(unique(tag.begin(), tag.end()), tag.end());
    ll ans = 0;
    if (tag.size() != n) {
        for (int i = 1; i < tag.size(); i++)
            ans += 1ll * (tag[i] - tag[i - 1]) * ask(tag[i - 1] + tag[i], 2) % mo;
        output(ans % mo);
    } else {
        ll pre = 0, now;
        for (int i = 1; i < tag.size(); i++) {
            if (i == tag.size() - 1) now = 0;
            else now = ask(tag[i], 1);
            ans += 1ll * (tag[i] - tag[i - 1]) * (pre + now) % mo;
            pre = now;
        }
        output(ans % mo * qpow(2, mo - 2) % mo);
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
