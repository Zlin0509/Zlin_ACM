//
// Created by Zlin on 2025/11/14.
//

#include "bits/stdc++.h"
#define endl '\n'
#define mkp(a, b) make_pair(a, b)
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 2e5 + 10;

int n, a[N], tag[2][N];

inline void cal(int op) {
    stack<int> A, B;
    int p = 0;
    for (int i = 1; i <= n; i++) {
        while (!A.empty() && a[A.top()] < a[i]) p = max(p, A.top()), A.pop();
        while (!B.empty() && a[B.top()] > a[i]) p = max(p, B.top()), B.pop();
        if (a[i] > a[i + 1]) A.push(i);
        else B.push(i);
        tag[op][op ? n - i + 1 : i] = op ? n - p + 1 : p;
    }
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cal(0);
    reverse(a + 1, a + 1 + n);
    cal(1);
    int rx = 0, l, r;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        l = tag[0][i], r = tag[1][i];
        // cout << l << ' ' << r << endl;
        ans += 1ll * (r - i) * (i - l) - 1ll * max(0, i - 1 - l) * max(0, rx - i);
        rx = r;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
