//
// Created by Zlin on 2025/7/31.
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

int n, m;
vi ans, vis;
pii a[100010];

inline void Zlin() {
    cin >> n >> m;
    vis.assign(m + 1, 0);
    ans.assign(n * 2 + 1, 0);
    for (int i = 1; i <= m; i++) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + m + 1);
    for (int i = m, j = m; i; i--) {
        if (!vis[i]) {
            if (j > i) j = i;
            while (a[j - 1].second >= a[i].first) vis[--j] = -1;
            vis[i] = 1;
        }
    }
    for (int i = 1; i <= m; i++) if (vis[i] == 1) ans[a[i].first] = 1;
    int res = n;
    for (int i = 1; i <= n * 2; i++) res -= ans[i];
    if (res < 0) {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= n * 2 && res; i++) {
        if (!ans[i]) {
            ans[i] = 1;
            --res;
        }
    }
    for (int i = 1; i <= n * 2; i++) {
        ans[i] ? ++res : --res;
        if (res < 0) {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 1; i <= n * 2; i++) cout << (ans[i] ? '(' : ')');
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
