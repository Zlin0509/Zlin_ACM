//
// Created by 27682 on 2025/11/4.
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

int n, k, a[N];
ll sum[N];
map<int, int> cnt;

inline ll cal(int i, int j) {
    ll res = sum[n] - sum[i + j] + 1ll * a[i] * (j + 1);
    int x = min((ll) i - 1, 1ll * j * k);
    res += sum[i - 1] - sum[x] + 1ll * x * a[i];
    return res;
}

inline void Zlin() {
    cin >> n >> k;
    cnt.clear();
    for (int i = 1; i <= n; i++) cin >> a[i], cnt[a[i]]++;
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    ll ans = sum[n];
    for (int i = 1; i <= n; i++) {
        int l = 0, r = n - i;
        while (l + 2 < r) {
            int ml = l + (r - l) / 3, mr = r - (r - l) / 3;
            ll vl = cal(i, ml), vr = cal(i, mr);
            if (vl > vr) r = mr;
            else l = ml;
        }
        for (int j = l; j <= r; j++) ans = max(ans, cal(i, j));
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
