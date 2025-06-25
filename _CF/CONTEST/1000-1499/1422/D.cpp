//
// Created by 27682 on 2025/6/24.
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

constexpr int N = 1e5 + 10;
constexpr ll INF = 3e9;

int n, m, fx, fy, vis[2][N];
ll valx[N], valy[N];
pii a[N];

vi vx, vy, hx[N], hy[N];

priority_queue<tuple<ll, int, int> > pq;

inline void Zlin() {
    cin >> n >> m;
    cin >> a[0].first >> a[0].second;
    cin >> fx >> fy;
    vx.push_back(a[0].first);
    vy.push_back(a[0].second);
    for (int i = 1; i <= m; i++) {
        cin >> a[i].first >> a[i].second;
        vx.push_back(a[i].first);
        vy.push_back(a[i].second);
    }
    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    sort(vy.begin(), vy.end());
    vy.erase(unique(vy.begin(), vy.end()), vy.end());
    for (int i = 0; i <= m; i++) {
        a[i].first = lower_bound(vx.begin(), vx.end(), a[i].first) - vx.begin();
        a[i].second = lower_bound(vy.begin(), vy.end(), a[i].second) - vy.begin();
        hx[a[i].first].push_back(a[i].second);
        hy[a[i].second].push_back(a[i].first);
    }
    for (int i = 0; i < vx.size(); i++) valx[i] = INF;
    for (int i = 0; i < vy.size(); i++) valy[i] = INF;
    pq.push({0, 0, a[0].first});
    pq.push({0, 1, a[0].second});
    valx[a[0].first] = valy[a[0].second] = 0;
    while (!pq.empty()) {
        auto [val, op, id] = pq.top();
        pq.pop();
        if (vis[op][id]) continue;
        vis[op][id] = 1;
        if (!op) {
            for (int idx: hx[id]) {
                if (valy[idx] > valx[id]) {
                    valy[idx] = valx[id];
                    pq.push({-valy[idx], 1, idx});
                }
            }
            if (id && valx[id - 1] > valx[id] + vx[id] - vx[id - 1]) {
                valx[id - 1] = valx[id] + vx[id] - vx[id - 1];
                pq.push({-valx[id - 1], 0, id - 1});
            }
            if (id + 1 < vx.size() && valx[id + 1] > valx[id] + vx[id + 1] - vx[id]) {
                valx[id + 1] = valx[id] + vx[id + 1] - vx[id];
                pq.push({-valx[id + 1], 0, id + 1});
            }
        } else {
            for (int idx: hy[id]) {
                if (valx[idx] > valy[id]) {
                    valx[idx] = valy[id];
                    pq.push({-valx[idx], 0, idx});
                }
            }
            if (id && valy[id - 1] > valy[id] + vy[id] - vy[id - 1]) {
                valy[id - 1] = valy[id] + vy[id] - vy[id - 1];
                pq.push({-valy[id - 1], 1, id - 1});
            }
            if (id + 1 < vy.size() && valy[id + 1] > valy[id] + vy[id + 1] - vy[id]) {
                valy[id + 1] = valy[id] + vy[id + 1] - vy[id];
                pq.push({-valy[id + 1], 1, id + 1});
            }
        }
    }
    ll ans = INF;
    for (int i = 0; i <= m; i++) {
        auto [x, y] = a[i];
        // cout << min(valx[x], valy[y]) << ' ' << vx[x] << ' ' << vy[y] << endl;
        ans = min(ans, min(valx[x], valy[y]) + abs(fx - vx[x]) + abs(fy - vy[y]));
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
