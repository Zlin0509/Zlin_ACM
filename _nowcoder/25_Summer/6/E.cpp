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

constexpr int N = 1e5 + 10;
constexpr ll INF = 1e18;

struct Dij_Tree {
    struct Node {
        int l, r;
    } t[N << 2];

    struct edge {
        int to;
        ll val;
    };

    vector<edge> e[N << 4];

    int dif = 5e5;
    int idx[N], vis[N << 4];
    ll dis[N << 4];


    void build(int i, int l, int r) {
        // cout << i << ' ' << l << ' ' << r << endl;
        dis[i] = dis[i + dif] = INF;
        vis[i] = vis[i + dif] = 0;
        t[i].l = l, t[i].r = r;
        if (l == r) {
            // 底边互相连接
            e[i].push_back({i + dif, 0});
            e[i + dif].push_back({i, 0});
            idx[l] = i;
            return;
        }
        // 第一个对应坐标
        e[i].push_back({i << 1, 0});
        e[i].push_back({i << 1 | 1, 0});
        // 第二个对应坐标
        e[(i << 1) + dif].push_back({i + dif, 0});
        e[(i << 1 | 1) + dif].push_back({i + dif, 0});

        int mid = l + r >> 1;
        build(i << 1, l, mid);
        build(i << 1 | 1, mid + 1, r);
    }

    // op 1 表示从点到线段 点到线段说明是第二棵树的点s 连接 第一棵树的对应node
    // op 0 表示从线段到点 线段到点说明是第二棵树的对应node 连接 第一棵树的点s
    void update(int i, int l, int r, int s, int val, int op) {
        if (t[i].r < l || t[i].l > r) return;
        if (t[i].l >= l && t[i].r <= r) {
            if (op) e[idx[s] + dif].push_back({i, val});
            else e[i + dif].push_back({idx[s], val});
            return;
        }
        update(i << 1, l, r, s, val, op);
        update(i << 1 | 1, l, r, s, val, op);
    }

    void dij(int s) {
        priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<> > pq;
        dis[idx[s]] = 0;
        pq.emplace(dis[idx[s]], idx[s]);
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            // cout << (u >= dif ? u - dif : u) << ' ' << dis[u] << endl;
            for (auto [v, val]: e[u]) {
                if (dis[v] > dis[u] + val) {
                    dis[v] = dis[u] + val;
                    pq.emplace(dis[v], v);
                }
            }
        }
    }

    ll query(int i) { return dis[idx[i]]; }
} t;

inline void Zlin() {
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
