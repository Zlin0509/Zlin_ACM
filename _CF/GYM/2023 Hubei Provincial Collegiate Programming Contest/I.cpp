#include <bits/stdc++.h>

using namespace std;
using ll = __int128;

const int N = 1e7 + 5;
const int M = 1e6 + 5;
const ll inf = 1e9;
const ll mod = 998244353;
long long vis[N], isprime[N], cnt, n, a[N], xx;

void init() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) isprime[++cnt] = i;
        for (int j = 1; j <= cnt && isprime[j] * i < N; j++) {
            vis[isprime[j] * i] = 1;
            if (i % isprime[j] == 0) break;//每个合数只能由自己最小的质因子筛掉，所以判断成功就break;
        }
    }//O(n)
}

vector<pair<ll, ll>> v;
ll ans1 = inf;

ll q_pow(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * x;
        x = x * x;
        n >>= 1;
    }
    return res;
}

void extend_gcd(ll a, ll b, ll &d, ll &x, ll &y) {
    if (!b) {
        d = a;
        x = 1;
        y = 0;
    }
    else {
        extend_gcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}

void dfs(ll x, ll res1) {
    if (x == v.size()) {
        ll res2 = xx / res1;
        ll _x, _y, b1, x1, y1, c, d;
        ll a = res1, b = res2;
        if (a == 1 || b == 1) {
            ans1 = min(max(a, b) - 1, ans1);
            return;
        }
        // cout << a << " " << b << "\n";
        c = 1;
        extend_gcd(a, b, d, _x, _y);
        b1 = b / d;
        x1 = (_x + b1) * (c / d);
        x1 = (x1 % b1 + b1) % b1;
        y1 = (c - a * x1) / b;
        ll xx = x1 * a, yy = y1 * b;
        if (xx < 0)xx = -xx;
        if (yy < 0)yy = -yy;
        // cout << xx << " " << yy << "\n";
        ans1 = min(ans1, min(xx, yy));
        c = -1;
        extend_gcd(a, b, d, _x, _y);
        b1 = b / d;
        x1 = (_x + b1) * (c / d);
        x1 = (x1 % b1 + b1) % b1;
        y1 = (c - a * x1) / b;
        xx = x1 * a, yy = y1 * b;
        if (xx < 0)xx = -xx;
        if (yy < 0)yy = -yy;
        ans1 = min(ans1, min(xx, yy));
        // cout << xx << " " << yy << "\n";
        return;
    }
    dfs(x + 1, res1 * q_pow(v[x].first, v[x].second));
    dfs(x + 1, res1);
}

void solve() {
    cin >> n;
    long long res = 1, x = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        x = __gcd(res, a[i]);
        res = res / x * a[i];
    }
    xx = res;
    res *= 2;
    xx *= 2;
    for (int i = 1; i <= cnt; i++) {
        ll x = isprime[i];
        ll cnt = 0;
        while (res % x == 0) {
            res /= x;
            cnt++;
        }
        if (cnt) v.push_back({x, cnt});
    }
    dfs(0, 1);
    // cout << ans1 << ' ' << ans2 << "\n";
    // cout << xx << '\n';
    // ll ans=inf;
    cout << (long long) ans1 << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int _ = 1; //cin >> _;
    while (_--) solve();
    return 0;
}