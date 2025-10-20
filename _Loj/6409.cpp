//
// Created by Zlin on 2025/10/20.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

using T = long long;

constexpr ldb eps = 1e-9;

struct Point {
    T x, y;

    T operator*(const Point &a) { return x * a.x + y * a.y; }
    T operator^(const Point &a) { return x * a.y - y * a.x; }

    int toleft(const Point &a) {
        T t = (*this) ^ a;
        return (t > 0) - (t < 0);
    }
};

struct Line {
    T p, v;
};

vector<Line> cut(const std::vector<Line> &o, Line l) {
    std::vector<Line> res;
    int n = size(o);
    for (int i = 0; i < n; ++i) {
        Line a = o[i], b = o[(i + 1) % n], c = o[(i + 2) % n];
        int va = check(a, b, l), vb = check(b, c, l);
        if (va > 0 || vb > 0 || (va == 0 && vb == 0)) {
            res.push_back(b);
        }
        if (va >= 0 && vb < 0) {
            res.push_back(l);
        }
    }
    return res;
}

vector<vector<Line> > voronoi(vector<Point> p) {
    int n = p.size();
    auto b = p;
    shuffle(b.begin(), b.end(), gen);
    const db V = 3e4;
    std::vector<std::vector<line> > a(n, {
                                          {V, 0, V * V}, {0, V, V * V},
                                          {-V, 0, V * V}, {0, -V, V * V},
                                      });
    for (int i = 0; i < n; ++i) {
        for (const Point &x: b)
            if ((x - p[i]).abs() > eps) {
                a[i] = cut(a[i], bisector(p[i], x));
            }
    }
    return a;
}

inline void Zlin() {
    int n;
    cin >> n;
    vector<Point> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].x >> v[i].y;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
