//
// Created by Zlin on 2025/8/22.
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

inline void Zlin() {
    int n, pos = 0, mx = 0;
    cin >> n;
    vi a(n), ans1(n), ans2(n, 0);
    for (int &it: a) cin >> it;
    set<int> st;
    for (int i = 1; i <= n; i++) st.insert(i);
    while (!st.empty()) {
        if (mx < a[pos]) ans1[pos] = a[pos], st.erase(st.find(a[pos]));
        else {
            ans1[pos] = *st.begin();
            st.erase(st.begin());
        }
        mx = max(mx, ans1[pos++]);
    }
    for (int i = 1; i <= n; i++) st.insert(i);
    for (int i = 0; i < n; i++) {
        if (!i || a[i] != a[i - 1]) {
            st.erase(a[i]);
            ans2[i] = a[i];
        }
    }
    pos = mx = 0;
    while (!st.empty()) {
        if (ans2[pos]) mx = max(mx, ans2[pos]);
        else {
            auto it = prev(st.lower_bound(mx));
            ans2[pos] = *it;
            st.erase(it);
        }
        ++pos;
    }
    for (int it: ans1) cout << it << ' ';
    cout << endl;
    for (int it: ans2) cout << it << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
