//
// Created by Zlin on 2025/9/26.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

using T = long long;

constexpr T eps = 1e-9;
constexpr T INF = numeric_limits<T>::max();
constexpr T PI = 3.1415926535897932384l;

struct Point {
    T x, y;

    bool operator<(const Point &other) const {
        if (abs(x - other.x) < eps) return y < other.y - eps;
        return x < other.x - eps;
    }

    Point operator-(const Point &other) const { return {x - other.x, y - other.y}; }
    Point operator-() const { return {-x, -y}; }
    T operator^(const Point &other) const { return x * other.y - y * other.x; }

    int toleft(const Point &a) const {
        const auto t = (*this) ^ a;
        return (t > eps) - (t < -eps);
    } // to-left 测试
};

struct Line {
    Point p, v;

    int toleft(const Point &a) const { return v.toleft(a - p); }
};

struct Seg {
    Point a, b;
};

struct Polygon {
    vector<Point> p;

    size_t nxt(const size_t i) const { return i == p.size() - 1 ? 0 : i + 1; }
    size_t pre(const size_t i) const { return i == 0 ? p.size() - 1 : i - 1; }
};

struct Convex : Polygon {
    template<typename F>
    size_t extreme(const F &dir) const {
        const auto &p = this->p;
        const auto check = [&](const size_t i) { return dir(p[i]).toleft(p[this->nxt(i)] - p[i]) >= 0; };
        const auto dir0 = dir(p[0]);
        const auto check0 = check(0);
        if (!check0 && check(p.size() - 1)) return 0;
        const auto cmp = [&](const Point &v) {
            const size_t vi = &v - p.data();
            if (vi == 0) return 1;
            const auto checkv = check(vi);
            const auto t = dir0.toleft(v - p[0]);
            if (vi == 1 && checkv == check0 && t == 0) return 1;
            return checkv ^ (checkv == check0 && t <= 0);
        };
        return partition_point(p.begin(), p.end(), cmp) - p.begin();
    }

    pair<size_t, size_t> tangent(const Line &a) const {
        const size_t i = extreme([&](...) { return a.v; });
        const size_t j = extreme([&](...) { return -a.v; });
        return {i, j};
    }
};

Convex convexhull(vector<Point> p) {
    vector<Point> res;
    if (p.empty()) return {res};
    const auto check = [](const vector<Point> &st, const Point &u) {
        const auto b1 = st.back(), b2 = *prev(st.end(), 2);
        return (b2 - b1).toleft(u - b1) <= 0;
    };
    sort(p.begin(), p.end());
    for (const auto &u: p) {
        while (res.size() > 1 && check(res, u)) res.pop_back();
        res.emplace_back(u);
    }
    int siz = res.size();
    res.pop_back();
    reverse(p.begin(), p.end());
    for (const auto &u: p) {
        while (res.size() > siz && check(res, u)) res.pop_back();
        res.emplace_back(u);
    }
    res.pop_back();
    return {res};
}

inline void Zlin() {
    int n;
    cin >> n;
    Convex a;
    for (int i = 0; i < n; i++) {
        T x, y;
        cin >> x >> y;
        a.p.emplace_back(x, y);
    }
    a = convexhull(a.p);
    Point p1, p2;
    while (cin >> p1.x >> p1.y >> p2.x >> p2.y) {
        Line l = Line(p1, p2 - p1);
        const auto check = [](const Line &l, const Seg &s) {
            return l.toleft(s.a) * l.toleft(s.b) < 0;
        };
        if (a.p.size() > 2) {
            auto res = a.tangent(l);
            cout << (check(l, Seg(a.p[res.first], a.p[res.second])) ? "BAD" : "GOOD") << endl;
        } else if (a.p.size() == 2) {
            cout << (check(l, Seg(a.p[0], a.p[1])) ? "BAD" : "GOOD") << endl;
        } else cout << "GOOD" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
