//
// Created by 27682 on 2025/3/26.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef __int128 i128;

constexpr int N = 810;
constexpr ll inf = 1e16;

int n, m, p;
i128 w[N], vis[N];

struct edge {
    i128 to, val;
};

vector<edge> e[N];

struct node {
    i128 val, time, mx;

    bool operator<(const node &x) const {
        if (time != x.time) return time < x.time;
        return val < x.val;
    }
} dis[N];

bool check(ll x) {
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
        dis[i] = {0, 0};
    }
    priority_queue<pair<node, int> > pq;
    dis[1] = {p, x};
    pq.push({dis[1], 1});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v,val]: e[u]) {
        }
    }
}

inline void Zlin() {
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        e[i].clear();
    }
    for (int i = 1, x; i <= n; i++) cin >> x, w[i] = x;
    for (int i = 1, u, v, s; i <= m; i++) {
        cin >> u >> v >> s;
        e[u].push_back({v, s});
    }
    ll l = 0, r = 1e14, mid;
    while (l < r) {
        mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    if (l == 1e14) l = -1;
    ll ans = l;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
