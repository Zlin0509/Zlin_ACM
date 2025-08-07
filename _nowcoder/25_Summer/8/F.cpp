//
// Created by Zlin on 2025/8/7.
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

int idx[10];

vi have[100];

int n, m;
int a[1000];

inline int cal(const vi &a) {
    int ans = 0, base = 7;
    set<int> st;
    for (int i = 0; i < n; i++) st.insert(a[i] % 10);
    for (int i = 0; i < 1 << 7; i++) {
        set<int> used;
        for (int it: st) {
            int res = idx[it];
            used.insert(res & i);
        }
        if (used.size() == st.size()) {
            int cnt = 0;
            for (int j = 0; j < 7; j++) if (i >> j & 1) ++cnt;
            base = min(base, cnt);
        }
    }
    ans += base;
    if (m <= 1) return ans;

    return ans;
}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 21;
    vi ta(n);
    for (int i = 0; i < n; i++) {
        int ax = a[i] / 100, bx = a[i] % 100 / 10, cx = a[i] % 10;
        ta[i] = ax * 100 + bx * 10 + cx;
    }
    ans = min(ans, cal(ta));
    for (int i = 0; i < n; i++) {
        int ax = a[i] / 100, bx = a[i] % 100 / 10, cx = a[i] % 10;
        ta[i] = ax * 100 + bx + cx * 10;
    }
    ans = min(ans, cal(ta));
    for (int i = 0; i < n; i++) {
        int ax = a[i] / 100, bx = a[i] % 100 / 10, cx = a[i] % 10;
        ta[i] = ax * 10 + bx * 100 + cx;
    }
    ans = min(ans, cal(ta));
    for (int i = 0; i < n; i++) {
        int ax = a[i] / 100, bx = a[i] % 100 / 10, cx = a[i] % 10;
        ta[i] = ax * 10 + bx + cx * 100;
    }
    ans = min(ans, cal(ta));
    for (int i = 0; i < n; i++) {
        int ax = a[i] / 100, bx = a[i] % 100 / 10, cx = a[i] % 10;
        ta[i] = ax + bx * 100 + cx * 10;
    }
    ans = min(ans, cal(ta));
    for (int i = 0; i < n; i++) {
        int ax = a[i] / 100, bx = a[i] % 100 / 10, cx = a[i] % 10;
        ta[i] = ax + bx * 10 + cx * 100;
    }
    ans = min(ans, cal(ta));
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    idx[0] = (1 << 1) + (1 << 2) + (1 << 3) + (1 << 5) + (1 << 6) + (1 << 7) >> 1;
    idx[1] = (1 << 3) + (1 << 6) >> 1;
    idx[2] = (1 << 1) + (1 << 3) + (1 << 4) + (1 << 5) + (1 << 7) >> 1;
    idx[3] = (1 << 1) + (1 << 3) + (1 << 4) + (1 << 6) + (1 << 7) >> 1;
    idx[4] = (1 << 2) + (1 << 3) + (1 << 4) + (1 << 6) >> 1;
    idx[5] = (1 << 1) + (1 << 2) + (1 << 4) + (1 << 6) + (1 << 7) >> 1;
    idx[6] = (1 << 1) + (1 << 2) + (1 << 4) + (1 << 5) + (1 << 6) + (1 << 7) >> 1;
    idx[7] = (1 << 1) + (1 << 3) + (1 << 6) >> 1;
    idx[8] = (1 << 1) + (1 << 2) + (1 << 3) + (1 << 4) + (1 << 5) + (1 << 6) + (1 << 7) >> 1;
    idx[9] = (1 << 1) + (1 << 2) + (1 << 3) + (1 << 4) + (1 << 6) + (1 << 7) >> 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
