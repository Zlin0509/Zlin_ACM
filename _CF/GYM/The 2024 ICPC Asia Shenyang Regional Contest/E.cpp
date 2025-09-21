//
// Created by 27682 on 2025/9/21.
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

constexpr ll inf = 1e12;
int a[4];
int m;
int val[16];
ll dp[1 << 16][16];

inline void Zlin() {
    cin >> m;
    int idx = 0;
    while (m--) {
        string s1, s2;
        cin >> s1 >> s2;
        int tmp = 0;
        for (auto it: s1) tmp = tmp * 2 + it - '0';
        for (auto it: s2) tmp = tmp * 2 + it - '0';
        idx |= 1 << tmp;
        cout << (1 << tmp) << ' ';
    }
    ll ans = inf;
    for (int i = 0; i < 16; i++) ans = min(ans, dp[idx][i]);
    cout << ans << endl;
}


int vis[1 << 16][16];

inline void dij() {
    priority_queue<pair<ll, pair<int, int> >, vector<pair<ll, pair<int, int> > >, greater<> > pq;
    for (int i = 0; i < 1 << 16; i++) for (int j = 0; j < 16; j++) dp[i][j] = inf;
    dp[0][0] = a[3];
    pq.emplace(dp[0][0], make_pair(0, 0));
    for (int i = 0; i < 16; i++) {
        pii u{1 << i, 0};
        for (int k = 0; k < 4; k++) if (!(i >> k & 1)) u.second ^= 1 << k;
        dp[1 << i][u.second] = val[i];
        pq.emplace(dp[1 << i][u.second], u);
    }
    while (!pq.empty()) {
        auto [u, base] = pq.top().second;
        pq.pop();
        if (vis[u][base]) continue;
        vis[u][base] = 1;
        for (int j = 0, v; j < 16; j++) {
            v = u | (1 << j);
            int basex = base;
            for (int k = 0; k < 4; k++) if (!(j >> k & 1)) basex ^= 1 << k;
            if (dp[v][basex] > dp[u][base] + val[base ^ j]) {
                dp[v][basex] = dp[u][base] + val[base ^ j];
                pq.emplace(dp[v][basex], make_pair(v, basex));
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    for (int i = 0; i < 4; i++) cin >> a[i];
    a[1] = min(a[0] * 2, a[1]);
    a[2] = min(a[0] * 2, a[2]);
    a[3] = min({a[0] * 4, a[1] * 2, a[2] * 2, a[3]});
    for (int i = 0; i < 16; i++) {
        vi tag;
        for (int j = 0; j < 4; j++) if (!(i >> j & 1)) tag.emplace_back(j);
        if (tag.size() == 4) val[i] = a[3];
        else if (tag.size() == 3) val[i] = min({a[0] * 3, a[0] + a[1], a[0] + a[2], a[0] + a[3]});
        else if (tag.size() == 2) {
            if ((tag[0] == 1 && tag[1] == 2) || (tag[0] == 0 && tag[1] == 3)) {
                val[i] = a[0] * 2;
            } else if (tag[0] + 2 == tag[1]) {
                val[i] = a[2];
            } else {
                val[i] = a[1];
            }
        } else if (tag.size() == 1) val[i] = a[0];
        else val[i] = a[3] * 2;
    }
    dij();
    while (ttt--) Zlin();
    return 0;
}
