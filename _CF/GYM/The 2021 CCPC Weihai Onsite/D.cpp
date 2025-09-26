//
// Created by Zlin on 2025/9/26.
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

constexpr int N = 1e6 + 10;
constexpr ll p = 11451411, mo = 998244353;

string s;
int n;
vi st;
ll h[N], fac[N];

inline void Zlin() {
    cin >> s;
    n = s.length();
    s = ' ' + s;
    for (int i = 1; i <= n; i++) h[i] = (h[i - 1] * p % mo + s[i]) % mo;
    for (int i = (n + 1) / 2; i < n; i++) {
        ll lx = (h[n] - h[i] * fac[n - i] % mo + mo) % mo, rx = h[n - i];
        if (lx == rx) st.emplace_back(i);
    }
    sort(st.begin(), st.end());
    int q;
    cin >> q;
    while (q--) {
        int i;
        cin >> i;
        int ans = lower_bound(st.begin(), st.end(), max(i, n - i + 1)) - st.begin();
        cout << st.size() - ans << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * p % mo;
    while (ttt--) Zlin();
    return 0;
}
