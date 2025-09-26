//
// Created by Zlin on 2025/9/26.
//

#include <iterator>

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 1e5 + 5;
constexpr int M = 2e6 + 50;
constexpr db eps = 1e-4;

int idx[M];
ll n, k, q, cnt;
ll a[N], b[N], sum[N];
db ans[101];

inline void Zlin() {
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];
    cnt = n * (n - 1) / 2;
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
        idx[a[i]] = i;
    }
    for (int i = 1; i < M; i++) idx[i] = max(idx[i], idx[i - 1]);
    for (int i = 1; i < n; i++) ans[0] += 1.0 * (sum[n] - sum[i] + a[i] * (n - i)) / cnt;
    for (int c = 1; c <= k; c++) {
        ans[c] = 0;
        for (int i = 1; i < n; i++) {
            int tmp = ans[c - 1] - a[i];
            if (tmp <= 0) tmp = i + 1;
            else tmp = max(idx[tmp] + 1, i + 1);
            ans[c] += 1.0 * (sum[n] - sum[tmp - 1] + a[i] * (n - tmp + 1)) / cnt;
            ans[c] += 1.0 * ans[c - 1] * (tmp - i - 1) / cnt;
        }
    }
    cout << fixed << setprecision(9) << ans[k] << endl;
    while (q--) {
        int x, y, c;
        cin >> x >> y >> c;
        if (c) {
            db res = b[x] + b[y];
            if (fabs(res - ans[c - 1]) <= eps) cout << "both" << endl;
            else if (res > ans[c - 1]) cout << "accept" << endl;
            else cout << "reselect" << endl;
        } else cout << "accept" << endl;
    }
}

/*

3 100 2
30 40 50
1 2 0
1 3 0

*/

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
