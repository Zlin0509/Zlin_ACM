#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = double;
using ull = unsigned long long;
const int N = 5e5 + 5;
const int MAXN = 2e5 + 5;
const int M = 1e7 + 1;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const ull base = 131;
ll n, a[N], m, d[N], d2[N];
pair<ll, ll> b[N];
vector<ll> g[N], g2[N];

struct Node {
    ll l, r, id;
};

vector<Node> g3[N];

struct cmp {
    bool operator()(const Node a, const Node b) const {
        return a.l < b.l;
    }
};

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        g[i].clear();
        g2[i].clear();
        g3[i].clear();
        d[i] = d2[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        ll x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g2[y].push_back(x);
        d[y]++;
        d2[x]++;
    }
    queue<ll> q;
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) q.push(i);
        b[i].first = 1;
        if (a[i]) b[i].first = a[i];
    }
    while (q.size()) {
        ll x = q.front();
        q.pop();
        cnt++;
        for (auto v: g[x]) {
            d[v]--;
            b[v].first = max(b[x].first + 1, b[v].first);
            if (!d[v]) q.push(v);
        }
    }
    if (cnt < n) {
        cout << "qqq-1\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (d2[i] == 0) q.push(i);
        b[i].second = n;
        if (a[i]) b[i].second = a[i];
    }
    while (q.size()) {
        ll x = q.front();
        q.pop();
        for (auto v: g2[x]) {
            d2[v]--;
            b[v].second = min(b[x].second - 1, b[v].second);
            if (!d2[v]) q.push(v);
        }
    }
    for (int i = 1; i <= n; i++) g3[b[i].second].push_back({b[i].first, b[i].second, i});
    priority_queue<Node, vector<Node>, cmp> pq;
    for (int i = n; i >= 1; i--) {
        for (auto o: g3[i]) pq.push(o);
        if (pq.size() || pq.top().l > i) {
            cout << "-1\n";
            return;
        }
        a[pq.top().id] = i;
        pq.pop();
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";
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
