//
// Created by Zlin on 2025/8/4.
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

int a[1010][15], n, m, k;
int p[15], val[15];

inline void cal() {
    for (int i = 1; i <= m; i++) val[i] = 0;
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= m; j++)
            val[j] = max(val[j], a[p[i]][j]);
}

inline void Zlin() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];
    k = min(m, k);
    queue<int> q;
    for (int i = 1; i <= k; i++) p[i] = i;
    for (int i = k + 1; i <= n; i++) q.emplace(i);
    int cnt = n * (k + 1);
    while (!q.empty() && --cnt) {
        int j = q.front();
        q.pop();
        ll tag = 0, base = 0;
        for (int i = 1, tmp; i <= k; i++) {
            ll res1 = 0, res2 = 0;
            cal();
            for (int z = 1; z <= m; z++) res1 += val[z];
            tmp = p[i], p[i] = j;
            cal();
            for (int z = 1; z <= m; z++) res2 += val[z];
            if (res2 - res1 > base) {
                base = res2 - res1;
                tag = i;
            }
            p[i] = tmp;
        }
        if (tag) {
            q.emplace(p[tag]);
            p[tag] = j;
        } else q.emplace(j);
        for (int i = 1; i <= k; i++) cout << p[i] << ' ';
        cout << endl;
    }
    cal();
    ll ans = 0;
    for (int i = 1; i <= m; i++) ans += val[i];
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
