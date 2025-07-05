//
// Created by Zlin on 2025/7/4.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int N = 6e5 + 10;
constexpr int INF = 1e9;

int n, k, a[N], b[N], m1, m2, dis1[N], dis2[N];
vi e1[N], e2[N];

inline void bfs(const vi e[], int dis[], int s) {
    fill(dis + 1, dis + 1 + n, INF);
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: e[u]) {
            if (dis[v] == INF) {
                dis[v] = (dis[u] + 1) % k;
                q.push(v);
            }
        }
    }
}

constexpr ll p = 731, mo = 998244353;
ll fac[N], cnt[2][2][N];

ll ghsh(const ll hsh[], int l, int r) {
    ll ret = hsh[r];
    if (l) ret = (ret - hsh[l - 1] * fac[r - l + 1] % mo + mo) % mo;
    return ret;
}

inline void Zlin() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) e1[i].clear(), e2[i].clear();
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m1;
    for (int i = 1, u, v; i <= m1; i++) {
        cin >> u >> v;
        e1[u].emplace_back(v);
    }
    for (int i = 1; i <= n; i++) cin >> b[i];
    cin >> m2;
    for (int i = 1, u, v; i <= m2; i++) {
        cin >> u >> v;
        e2[u].emplace_back(v);
    }
    bfs(e1, dis1, 1);
    bfs(e2, dis2, 1);
    for (auto &i: cnt) for (auto &j: i) fill(j, j + k * 3, 0);
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        cnt1 += a[i], cnt2 += b[i];
        cnt[0][a[i]][dis1[i]]++;
        cnt[0][a[i]][dis1[i] + k]++;
        cnt[0][a[i]][dis1[i] + k * 2]++;
        cnt[1][b[i]][dis2[i]]++;
        cnt[1][b[i]][dis2[i] + k]++;
        cnt[1][b[i]][dis2[i] + k * 2]++;
    }
    if (cnt1 + cnt2 != n) {
        cout << "NO" << endl;
        return;
    }
    if (!cnt1 || !cnt2) {
        cout << "YES" << endl;
        return;
    }
    for (auto &i: cnt) {
        for (auto &j: i) {
            for (int z = 1; z < k * 3; z++) {
                j[z] = (j[z] + j[z - 1] * p % mo) % mo;
            }
        }
    }
    for (int i = 0; i < k; i++) {
        if (ghsh(cnt[1][0], 0, k - 1) == ghsh(cnt[0][1], i, i + k - 1) && ghsh(cnt[1][1], 0, k - 1) == ghsh(
                cnt[0][0], i + 2, i + 2 + k - 1)) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * p % mo;
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
