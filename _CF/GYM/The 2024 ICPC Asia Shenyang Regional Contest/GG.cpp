#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll inf = 1e18;
const int N = 1e3 + 5;
const int M = 2e6 + 1;
const ll mod = 1e9 + 7;
const ull base = 131;
ll n;
bool vis[N];

struct Node {
    ll x, y;

    bool operator <(const Node &u) const {
        return x ^ u.x ? x < u.x : y < u.y;
    }
} a[N];

ll cnt[N];
pair<ll, ll> zz = {1, 4}, dz = {1, 2};

pair<ll, ll> change(pair<ll, ll> x, ll op) {
    ll xx = op * x.second;
    x.first *= 4;
    x.second *= 4;
    x.first += xx;
    ll g = abs(__gcd(x.first, x.second));
    x.first /= g;
    x.second /= g;
    return x;
}

struct Node2 {
    ll op;
    pair<ll, ll> x, y;
} w[N];

pair<ll, ll> operator+(pair<ll, ll> &lx, pair<ll, ll> &rx) {
    ll g = abs(__gcd(lx.second, rx.second));
    ll lcm = rx.second * lx.second / g;
    lx.first *= lcm / lx.second;
    lx.second = lcm;
    rx.first *= lcm / rx.second;
    rx.second = lcm;
    pair<ll, ll> xx = {rx.first + lx.first, lcm};
    g = abs(__gcd(xx.first, xx.second));
    xx.first /= g;
    xx.second /= g;
    return xx;
}

pair<ll, ll> operator-(pair<ll, ll> &rx, pair<ll, ll> &lx) {
    ll g = abs(__gcd(lx.second, rx.second));
    ll lcm = rx.second * lx.second / g;
    lx.first *= lcm / lx.second;
    lx.second = lcm;
    rx.first *= lcm / rx.second;
    rx.second = lcm;
    pair<ll, ll> xx = {rx.first - lx.first, lcm};
    g = abs(__gcd(xx.first, xx.second));
    xx.first /= g;
    xx.second /= g;
    return xx;
}

pair<ll, ll> operator*(pair<ll, ll> &rx, pair<ll, ll> &lx) {
    pair<ll, ll> xx = {rx.first * lx.second + lx.first * rx.second, lx.second * rx.second};
    ll g = abs(__gcd(xx.first, xx.second));
    xx.first /= g;
    xx.second /= g;
    return xx;
}

pair<ll, ll> operator/(pair<ll, ll> &rx, pair<ll, ll> &lx) {
    swap(lx.first, lx.second);
    return lx * rx;
}

void solve() {
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    vector<ll> v;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
        cnt[a[i].x]++;
        v.push_back(a[i].x);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < v.size(); i++) {
        w[i].x = w[i].y = {0, 1};
        if (cnt[v[i]] == 1) {
            if (i > 0 && i + 1 < v.size()) {
                cout << "? " << v[i] << " " << 1 << endl;
                w[i].op = 0;
                cin >> w[i].x.first >> w[i].x.second;
                w[i].y = w[i].x;
            }
        } else {
            w[i].op = 1;
            pair<ll, ll> lx = change({v[i], 1}, -1), rx = change({v[i], 1}, 1);
            if (i) {
                cout << "? " << lx.first << " " << lx.second << endl;
                cin >> w[i].x.first >> w[i].x.second;
            }
            if (i + 1 < v.size()) {
                cout << "? " << rx.first << " " << rx.second << endl;
                cin >> w[i].y.first >> w[i].y.second;
            }
        }
    }
    pair<ll, ll> ans = {0, 1};

    for (int i = 1; i < v.size(); i++) {
        pair<ll, ll> lx = w[i - 1].y, rx = w[i].x;
        ll h = v[i] - v[i - 1];
        pair<ll, ll> xx = (rx - lx);
        pair<ll, ll> yy = {1, h};
        xx = xx * yy;
        if (w[i].op) {
            pair<ll, ll> o = xx * zz;
            rx = rx + o;
        }
        if (w[i - 1].op) {
            xx.first *= -1;
            pair<ll, ll> o = xx * zz;
            lx = lx + o;
        }
        lx = lx + rx;
        swap(yy.first, yy.second);
        lx = lx * yy;
        lx = lx * dz;
        cout << lx.first << ' ' << lx.second << endl;
        ans = ans + lx;
    }
    cout << ans.first << " " << ans.second << "\n";
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
