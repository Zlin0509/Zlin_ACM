//
// Created by Zlin on 2025/10/8.
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

int tag[66], cnt[66], n;
ll k, a[N], ans, all, base;

inline void dfs(int dep, ll pre) {
    if (pre + base > k) return;
    if (dep == -1) {
        ++ans;
        return;
    }
    if (tag[dep] != -1) dfs(dep - 1, pre);
    else {
        if (all % (1ll << dep) + (1ll << dep) + base + pre <= k) {
            ans += 1ll << cnt[dep];
        } else {
            dfs(dep - 1, pre);
            dfs(dep - 1, pre + (1ll << dep));
        }
    }
}

inline void Zlin() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n == 1) {
        cout << k + 1 << endl;
        return;
    }
    for (int t = 61, res, tmp; ~t; t--) {
        ll dif = 1ll << (t + 1);
        vector<pair<ll, int> > vx;
        for (int i = 1; i <= n; i++) vx.emplace_back(a[i] / dif, i);
        sort(vx.begin(), vx.end());
        for (int i = 0; i < vx.size(); i++) {
            vx[i].second = a[vx[i].second] >> t & 1;
            // cout << vx[i].first << ' ' << vx[i].second << endl;
        }
        res = tmp = -1;
        for (int i = 1; i < vx.size(); i++) {
            if (vx[i].first != vx[i - 1].first) {
                if (tmp != -1) {
                    if (res != -1 && res != tmp) {
                        cout << 0 << endl;
                        return;
                    }
                    res = tmp;
                }
                tmp = -1;
            } else if (vx[i].second != vx[i - 1].second) {
                if (tmp == -1) {
                    tmp = vx[i - 1].second;
                } else if (tmp != vx[i - 1].second) {
                    cout << 0 << endl;
                    return;
                }
            }
        }
        if (tmp != -1) {
            if (res != -1 && res != tmp) {
                cout << 0 << endl;
                return;
            }
            res = tmp;
        }
        tag[t] = res;
    }
    memset(cnt, 0, sizeof(cnt));
    all = base = 0;
    for (int i = 0; i < 62; i++) {
        if (tag[i] == -1) {
            cnt[i] = 1;
            all += 1ll << i;
        } else if (tag[i] == 1) {
            base += 1ll << i;
        }
        if (i) cnt[i] += cnt[i - 1];
    }
    if (base > k) {
        cout << 0 << endl;
        return;
    }
    ans = 0;
    dfs(61, 0);
    cout << ans << endl;
    // for (int i = 0; i <= k; i++) {
    //     if ((a[1] ^ i) <= (a[2] ^ i)) {
    //         cout << i << endl;
    //     }
    // }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
