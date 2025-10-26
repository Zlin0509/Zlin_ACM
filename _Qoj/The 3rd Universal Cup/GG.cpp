#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lb = long double;
using ull = unsigned long long;
const int N = 1e5 + 5;
const int M = 8e5 + 2;
const ll mod = 998244353;
const ll inf = 1e18;
const ull base = 131;
const ull base2 = 32423;
ll n, a[N], b[N], c[N], p[N], q[N];

struct Node {
    ll a, b;
};

vector<Node> v, w;
vector<ll> z;
ll dv[N], dw[N];

bool check(ll mid) {
    ll idv = 0, idw = 0;
    for (auto o: v) {
        ll xx = 1;
        ll a1 = mid - o.b;
        if (a1 < 0) a1 = -a1, xx = -xx;
        ll a2 = o.a;
        if (a2 < 0) a2 = -a2, xx = -xx;
        ll x;
        if (xx > 0) {
            x = a1 / a2;
        } else {
            x = -((a1 + a2 - 1) / a2);
        }
        // cout << o.a << " " << o.b << " " << x << "\n";
        dv[++idv] = x;
    }
    for (auto o: w) {
        ll x = (mid - o.b + o.a - 1) / o.a;
        dw[++idw] = x;
        // cout << o.a << " " << o.b << " " << x << "\n";
    }
    sort(dv + 1, dv + idv + 1);
    sort(dw + 1, dw + idw + 1);
    p[0] = q[n + 1] = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        p[i] = p[i - 1];
        while (j <= idv && dv[j] < c[i]) {
            j++;
        }
        if (j <= idv) {
            p[i]++;
            j++;
        }
    }
    for (int i = n, j = idw; i >= 1; i--) {
        q[i] = q[i + 1];
        while (j > 0 && dw[j] > c[i]) {
            j--;
        }
        if (j) {
            q[i]++;
            j--;
        }
    }
    ll ans = 0, xx = 0;
    for (auto o: z) {
        if (o >= mid) xx++;
    }
    for (int i = 0; i <= n; i++) {
        ans = max(p[i] + q[i + 1] + xx, ans);
    }
    return ans >= (n + 1) / 2;
}

void solve() {
    v.clear();
    w.clear();
    z.clear();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] < 0) v.push_back({a[i], b[i]});
        else if (a[i] > 0)w.push_back({a[i], b[i]});
        else z.push_back(b[i]);
        cin >> c[i];
    }
    sort(c + 1, c + 1 + n);
    // cout << check(9) << "\n";
    ll l = -2e18 - 1, r = 2e18 + 1;
    while (l + 1 != r) {
        ll mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << "\n";
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
