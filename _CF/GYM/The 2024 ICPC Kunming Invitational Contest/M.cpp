//
// Created by Zlin on 2024/10/4.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef __int128 i128;

struct point {
    ll x, y;

    point operator-(const point a) const {
        return {x - a.x, y - a.y};
    }

    ll operator^(const point &a) const {
        return x * a.y - y * a.x;
    }
};

bool check_side(point a, point b, point c, point d) {
    ll f1 = (c - a) ^ (b - a), f2 = (d - a) ^ (b - a);
    if ((f1 > 0 && f2 > 0) || (f1 < 0 && f2 < 0)) return 0;
    return 1;
}

ll dis(point a, point b) { return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y); }

bool check(point a, point b, point o, i128 r) {
    i128 len = dis(a, b);
    i128 s = abs((a - o) ^ (b - o));
    return len * r * r <= s * s;
}

inline void Zlin() {
    ll n, rr;
    point o;
    cin >> n >> o.x >> o.y >> rr;
    vector<point> a(n << 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i + n] = a[i];
    }
    int l = 0, r = l + 1;
    ll s = a[0] ^ a[1], ans = 0;
    for (; l < n; l++) {
        while (check(a[l], a[r + 1], o, rr) && check_side(a[l], a[r + 1], a[l + 1], o)) {
            s += a[r] ^ a[r + 1];
            ++r;
            ans = max(ans, abs(s + (a[r] ^ a[l])));
        }
        s -= a[l] ^ a[l + 1];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}