//
// Created by Zlin on 2024/11/5.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int N = 2e5 + 10;
constexpr int inf = 1e9;

int n, m, k;
int h[N];
int f[N], in1[N], in2[N], dis1[N], dis2[N];
vi e1[N], e2[N], group[N];

inline int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }

inline void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    if (fx > fy) swap(fx, fy);
    f[fy] = fx;
}

struct node {
    int day, hour;
};

pll cal(const vi &have) {
    queue<int> q;
    for (int it: have)
        if (!in1[it])
            q.push(it);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: e1[u]) {
            dis1[v] = max(dis1[v], dis1[u] + (h[u] > h[v] ? 1 : 0));
            --in1[v];
            if (!in1[v]) q.push(v);
        }
    }
    for (int it: have)
        if (!in2[it])
            q.push(it);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: e2[u]) {
            dis2[v] = max(dis2[v], dis2[u] + (h[v] > h[u] ? 1 : 0));
            --in2[v];
            if (!in2[v]) q.push(v);
        }
    }

    int tag = 0;
    for (int it: have)
        tag = max({tag, dis1[it], dis2[it]});
    node lx{0, k}, rx{tag, 0};
    for (int it: have) {
        if (dis1[it] == tag) {
            rx.hour = max(rx.hour, h[it]);
        }
        if (dis2[it] == tag) {
            lx.hour = min(lx.hour, h[it]);
        }
    }
    return {lx.hour, 1ll * tag * k + rx.hour};
}

inline void Zlin() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        group[i].clear();
        e1[i].clear(), e2[i].clear();
        in1[i] = in2[i] = dis1[i] = dis2[i] = 0;
        f[i] = i;
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        merge(a, b);
        e1[a].push_back(b);
        e2[b].push_back(a);
        in1[b]++, in2[a]++;
    }
    int cnt = 0;
    while (1) {
        vi vis(n + 1);
        for (int i = 1; i <= n; i++) {
            if (!vis[find(i)]) vis[f[i]] = ++cnt;
            group[vis[f[i]]].push_back(i);
        }
        break;
    }

    multiset<ll> l, r;
    vector<pll> q;
    for (int i = 1; i <= cnt; i++) {
        pll u = cal(group[i]);
        l.insert(u.first);
        r.insert(u.second);
        q.push_back(u);
    }
    sort(q.begin(), q.end());
    ll ans = *prev(r.end()) - *l.begin();
    for (auto [lx, rx]: q) {
        l.erase(l.find(lx));
        r.erase(r.find(rx));
        lx += k;
        rx += k;
        l.insert(lx);
        r.insert(rx);
        lx = min(lx, *l.begin());
        rx = max(rx, *prev(r.end()));
        ans = min(ans, rx - lx);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
