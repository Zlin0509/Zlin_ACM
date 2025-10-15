#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;
using ull = unsigned long long;
const int N = 2e6 + 5;
const int M = 29;
const ll mod = 998244353;
const ll inf = 1e9;
const ull base = 131;
ll n, a[N], k;

struct Tree {
    int l, r, data;
} t[N << 2];

void update(ll p) {
    t[p].data = min(t[p << 1].data, t[p << 1 | 1].data);
}

void build(int p, int l, int r) {
    t[p].l = l;
    t[p].r = r;
    if (l == r) {
        t[p].data = inf;
        return;
    }
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    update(p);
}

void change(int p, int x, int y) {
    if (t[p].l == t[p].r) {
        t[p].data = y;
        return;;
    }
    int mid = t[p].l + t[p].r >> 1;
    if (x <= mid) change(p << 1, x, y);
    else change(p << 1 | 1, x, y);
    update(p);
}

int getnum(int p, int l, int r) {
    if (l > r) return inf;
    if (l <= t[p].l && t[p].r <= r) {
        return t[p].data;
    }
    int mid = t[p].l + t[p].r >> 1;
    int res = inf;
    if (l <= mid) res = min(res, getnum(p << 1, l, r));
    if (r > mid) res = min(res, getnum(p << 1 | 1, l, r));
    return res;
}

ll b[N], c[N];

struct Node {
    ll x, w;

    bool operator <(const Node &u) const {
        return w > u.w;
    }
};

ll d[N];
vector<Node> g[N];

void dijkstra(ll x) {
    for (int i = 0; i <= n * 2; i++) d[i] = 1e18;
    priority_queue<Node> pq;
    pq.push({x, d[x] = 0});
    while (pq.size()) {
        ll x = pq.top().x;
        pq.pop();
        for (auto v: g[x]) {
            ll y = v.x, w = v.w;
            if (d[y] > d[x] + w) {
                pq.push({y, d[y] = d[x] + w});
            }
        }
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i <= n * 2; i++) g[i].clear();
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]] = i;
    }
    build(1, 0, n);
    for (int i = n; i >= 1; i--) {
        ll id = b[i], res = inf;
        if (0 <= id - k) {
            res = min(getnum(1, id + 1, n), getnum(1, 0, id - k));
        } else {
            res = getnum(1, id + 1, (id - k + n) % n);
        }
        c[i + n] = res;
        res = inf;
        if (id + k <= n) {
            res = min(getnum(1, id + k, n), getnum(1, 0, id - 1));
        } else {
            res = getnum(1, (id + k) % n, id - 1);
        }
        c[i] = res;
        change(1, id, i);
    }
    ll id = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i] < k) continue;
        id = i;
        break;
    }
    if (!id) {
        cout << "0\n";
        return;
    }
    // cout << id << "\n";
    // for (int i=1;i<=n+n;i++) {
    //     if (c[i]^inf) {
    //         cout << i << " " << c[i] << "\n";
    //     }
    // }
    // c[0]=id;
    for (int i = 1; i <= (n << 1); i++) {
        if (c[i] == inf) continue;
        ll id = i, kk = 0;
        if (i > n) id -= n, kk = k;
        ll x = c[i], idx = (b[x] + kk - b[id] + n) % n;
        ll yy = idx;
        g[i].push_back({x, min(yy, n - yy)});
        yy = abs(idx - (k - 1));
        g[i].push_back({x + n, min(yy, n - yy)});
    }
    ll yy = b[id];
    g[0].push_back({id, min(yy, n - yy)});
    yy = abs(k - 1 - b[id]);
    g[0].push_back({id + n, min(yy, n - yy)});
    dijkstra(0);
    ll ans = 1e18;
    for (int i = 1; i <= n + n; i++) {
        if (c[i] == inf) {
            // cout << i << " " << min(d[i] , d[i+n]) << "\n";
            ans = min(ans, d[i]);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) solve();
    return 0;
}
