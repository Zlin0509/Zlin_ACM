//
// Created by Zlin on 2025/8/3.
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

constexpr int N = 1e5 + 10;

int n, m;
int a[N], x[N], t[N], b[N];
vi idx[N];

/*

 */

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i], idx[i].clear();
    for (int i = 1; i <= m; i++) cin >> x[i] >> t[i];
    for (int i = m; i; i--) idx[t[i]].emplace_back(i);
    set<int> st;
    ll ans = 0, res = 0, base = 0;
    for (int i = 1; i <= n; i++) {
        b[i] = a[i];
        if (!idx[i].empty()) {
            st.insert(idx[i].back());
            ans += b[i];
        } else base += b[i];
    }
    for (int i = 0, tag, tmp; i <= m; i++) {
        res = x[i];
        if (i) {
            ans -= b[t[i]];
            if (b[t[i]]) st.erase(i);

            b[t[i]] = a[t[i]];
            idx[t[i]].pop_back();

            if (!idx[t[i]].empty()) {
                ans += b[t[i]];
                st.insert(idx[t[i]].back());
            } else base += b[t[i]];
        }
        if (i == m) break;
        tag = x[i + 1] - x[i];
        if (ans + base < tag) break;
        vi stt;
        while (!st.empty() && tag) {
            int pos = *st.begin(), id = t[pos];
            st.erase(st.begin());
            tmp = min(tag, b[id]);
            ans -= tmp;
            tag -= tmp;
            b[id] -= tmp;
            if (b[id]) stt.emplace_back(pos);
        }
        base -= tag;
        for (int pos: stt) st.insert(pos);
    }
    cout << ans + base + res << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
