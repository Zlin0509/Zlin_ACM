//
// Created by Zlin on 2025/11/14.
//

#include "bits/stdc++.h"
#define endl '\n'
#define ll __int128
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll x1, y1;
    ll g = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

inline void write(ll x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    if (x < 0) {
        cout << '-';
        x = -x;
    }
    string s;
    while (x > 0) {
        s.push_back('0' + x % 10);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

inline void Zlin() {
    int _n, _x, _y, _vx, _vy;
    cin >> _n >> _x >> _y >> _vx >> _vy;
    ll n = _n, x = _x, y = _y, vx = _vx, vy = _vy;
    ll g = gcd(vx, vy);
    vx /= g, vy /= g;
    if (x % gcd(vx, n) || y % gcd(vy, n)) {
        cout << -1 << endl;
        return;
    }
    ll gx = gcd(vx, n), gy = gcd(vy, n);
    ll mx, kx, my, ky;
    exgcd(vx / gx, n / gx, mx, kx);
    exgcd(vy / gy, n / gy, my, ky);
    mx *= x / gx, my *= y / gy;
    mx = -mx, my = -my;
    if (max(my - mx, mx - my) % gcd(n / gx, n / gy) != 0) {
        cout << -1 << "\n";
        return;
    }
    g = gcd(n / gx, n / gy);
    ll k, l;
    exgcd(n / gx / g, n / gy / g, k, l);
    l = -l;
    k *= (my - mx) / g;
    ll M = mx + n / gx * k;
    M = (M % n + n) % n;
    ll X = M * vx + x, Y = M * vy + y;
    ll bx = X / n - 1, by = Y / n - 1, bs = (X + Y) / (2 * n), bt = (max(Y - X, X - Y)) / (2 * n);
    write(bx + by + bs + bt);
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
