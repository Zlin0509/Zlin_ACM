//
// Created by Zlin on 2025/11/3.
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

constexpr int N = 5e5 + 10;
constexpr int tt = 35;

int n;

inline int pre(int i, int k = 1) {
    return (i - k % n + n) % n;
}

inline int nxt(int i, int k = 1) {
    return (i + k % n) % n;
}

ll a[N << 1];
ll f[N << 1], bef[N << 1], g[N << 1], aft[N << 1];

inline ll getl(int i, int j) {
    ll now = 0;
    for (int k = i - j + 1 + n; k <= i + n; k++) now = (now + a[k]) / 2;
    return now;
}

inline ll getr(int i, int j) {
    ll now = 0;
    for (int k = i + j - 1; k >= i; k--) now = (now + a[k]) / 2;
    return now;
}

inline void Zlin() {
    cin >> n;
    // n = 100;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        // a[i] = i ? 1 : 2;
        a[i + n] = a[i];
    }
    if (n <= 75) {
        for (int i = 0; i < n; i++) {
            ll ans = 0;
            for (int j = 0; j < n; j++) {
                ll tmp = getl(pre(i), j) + getr(nxt(i), n - j - 1);
                ans = max(ans, tmp);
            }
            cout << ans + a[i] << ' ';
        }
        cout << endl;
        return;
    }
    for (int i = n; i < n * 2; i++) {
        ll tmp = 0;
        for (int j = i - tt + 1; j <= i; j++) tmp = (tmp + a[j]) / 2;
        f[i] = f[i - n] = tmp;
    }
    bef[tt - 1] = -1;
    for (int i = tt; i < n * 2; i++) {
        if ((f[i - 1] + a[i]) / 2 == f[i] + 1) bef[i] = i - tt;
        else if ((f[i - 1] + 1 + a[i]) / 2 == f[i] + 1) bef[i] = bef[i - 1];
        else bef[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        ll tmp = 0;
        for (int j = i + tt - 1; j >= i; j--) tmp = (tmp + a[j]) / 2;
        g[i] = g[i + n] = tmp;
    }
    aft[n * 2 - tt] = -1;
    for (int i = n * 2 - tt - 1; ~i; i--) {
        if ((g[i + 1] + a[i]) / 2 == g[i] + 1) aft[i] = i + tt;
        else if ((g[i + 1] + 1 + a[i]) / 2 == g[i] + 1) aft[i] = aft[i + 1];
        else aft[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        ll l = pre(i), r = nxt(i);
        ll tag1 = -1, tag2 = -1;
        if (bef[i - 1 + n] != -1 && i - 1 + n - bef[i - 1 + n] + 1 <= n - 1) tag1 = n + i - 1 - bef[i - 1 + n] + 1;
        if (aft[r] != -1 && aft[r] - r + 1 <= n - 1) tag2 = aft[r] - r + 1;
        ll ans = f[l] + g[r];
        if (tag1 != -1 && tag2 != -1 && tag1 + tag2 <= n - 1) ans = max(ans, f[l] + g[r] + 2);
        if (tag1 != -1) {
            if (n - 1 - tag1 < tt) ans = max(ans, f[l] + getr(r, n - tag1 - 1) + 1);
            else ans = max(ans, f[l] + g[r] + 1);
        }
        if (tag2 != -1) {
            if (n - 1 - tag2 < tt) ans = max(ans, getl(l, n - tag2 - 1) + g[r] + 1);
            else ans = max(ans, f[l] + g[r] + 1);
        }
        cout << ans + a[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
