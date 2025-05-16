#include <bits/stdc++.h>
using namespace std;
using ll = int;
using ull = unsigned long long;
const int N = 3e5 + 5;
const int M = 4e5 + 1;
const ll inf = 1e18;
const ull base = 1331;
const ll mod = 998244353;
ll n, m, k;

struct Node {
    ll l, r, id;
};

bool cmp(Node a, Node b) {
    return a.l < b.l;
}

vector<Node> g[N];
ll fa[N];

ll get(ll x) {
    if (x == fa[x]) return x;
    return fa[x] = get(fa[x]);
}

vector<Node> g2[N];

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    if (n == 1) {
        cout << "YES\n";
        return;
    }
    if (m > k * 2 + 3) {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i <= k; i++) {
        ll x1, x2, y;
        cin >> x1 >> x2 >> y;
        g[y].push_back({x1, x2, i});
    }
    for (int i = 1; i <= m; i++) {
        if (g[i].size()) {
            vector<Node> &o1 = g[i];
            if (o1.begin()->l == 1) {
                // cout<<"?"<<'\n';
                fa[get(o1.begin()->id)] = get(0);
            }
            auto o = --o1.end();
            if (o->r == n) {
                fa[get(o->id)] = get(0);
            }
        }
        g[i].push_back({0, 0, 0});
        g[i].push_back({n + 1, n + 1, 0});
        sort(g[i].begin(), g[i].end(), cmp);
        for (int j = 1; j < g[i].size(); j++) {
            ll l = g[i][j - 1].r + 1, r = g[i][j].l - 1;
            if (r >= l) {
                g2[i].push_back({l, r, 0});
            }
        }
    }
    for (int i = 0; i <= k; i++) {
        fa[i] = i;
    }
    for (auto o: g[1]) {
        ll id = o.id;
        fa[id] = get(0);
    }
    for (auto o: g[m]) {
        ll id = o.id;
        fa[id] = get(0);
    }
    for (int i = 1; i + 1 <= m; i++) {
        vector<Node> &o1 = g[i];
        vector<Node> &o2 = g[i + 1];
        ll len = 0;
        for (int j = 1, k = 0; j < o1.size(); j++) {
            ll l = o1[j - 1].r + 1, r = o1[j].l - 1;
            if (o1[j - 1].r + 1 == o1[j].l) {
                ll id1 = o1[j - 1].id, id2 = o1[j].id;
                ll u = get(id1), v = get(id2);
                fa[u] = v;
            }
            while (k < o2.size() && o2[k].r + 1 < o1[j].l) {
                ll _l = o2[k].r + 1;
                k++;
            }
            while (k < o2.size() && o2[k].l <= o1[j].r + 1) {
                ll id2 = o2[k].id, id1 = o1[j].id;
                ll u = get(id1), v = get(id2);
                fa[u] = v;
                k++;
            }
        }
    }
    for (int i = 1; i + 1 <= m; i++) {
        vector<Node> &o1 = g2[i];
        vector<Node> &o2 = g2[i + 1];
        ll len = 0;
        for (int j = 0, k = 0; j < o1.size(); j++) {
            ll l = o1[j].l, r = o1[j].r;
            while (k < o2.size() && o2[k].r < l) {
                if (j) {
                    ll l1 = o1[j - 1].l, r1 = o1[j - 1].r;
                    ll _l = o2[k].l, _r = o2[k].r;
                    ll L = max(l1, _l), R = min(r1, _r);
                    if (R - l + 1 >= 2) {
                        cout << "NO\n";
                        return;
                    }
                }
                k++;
            }
            if (k < o2.size()) {
                ll _l = o2[k].l, _r = o2[k].r;
                ll L = max(l, _l), R = min(r, _r);
                if (R - L + 1 >= 2) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    for (int i = 1; i <= k; i++) {
        if (get(i) ^ get(0)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1; // cin >> _;
    while (_--) solve();
    return 0;
}
