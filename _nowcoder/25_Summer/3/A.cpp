//
// Created by 27682 on 2025/7/22.
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

constexpr int N = 1416;

int n, f[N], ans[N][N], val[N];
vi need[N];
set<int> st[N];

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> f[i];
    for (int i = 1; i <= n; i++) {
        val[i] = n;
        for (int j = 1; j <= n; j++) {
            ans[i][j] = 0;
        }
    }
    set<int> st;
    for (int j = 0; j < n; j++) st.insert(j);
    for (int i = 1; i <= n && !st.empty(); i++) {
        if (*st.begin() != f[i]) {
            val[i] = *st.begin();
            st.erase(st.begin());
        } else if (st.size() > 1) {
            auto it = st.upper_bound(f[i]);
            val[i] = *it;
            st.erase(it);
        }
    }
    // for (int i = 1; i <= n; i++) cout << val[i] << ' ';
    // cout << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (f[j] > val[i]) {
                ans[i][j] = ans[j][i] = val[i];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << ans[i][j] << ' ';
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
