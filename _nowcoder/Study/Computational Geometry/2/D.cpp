//
// Created by 27682 on 2025/9/10.
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

constexpr db eps = 1e-9;

template<typename T>
struct Point {
    T x, y;

    bool operator==(const Point &a) const { return (abs(x - a.x) <= eps && abs(y - a.y) <= eps); }
    Point operator+(const Point &a) const { return {x + a.x, y + a.y}; }
    Point operator-(const Point &a) const { return {x - a.x, y - a.y}; }
    Point operator-() const { return {-x, -y}; }
    Point operator*(const T k) const { return {k * x, k * y}; }
    Point operator/(const T k) const { return {x / k, y / k}; }
    T operator*(const Point &a) const { return x * a.x + y * a.y; } //Dot
    T operator^(const Point &a) const { return x * a.y - y * a.x; } //Cross
    bool operator<(const Point &a) const {
        if (abs(x - a.x) <= eps) return y < a.y - eps;
        return x < a.x - eps;
    }

    bool is_par(const Point &a) const { return abs((*this) ^ a) <= eps; } // 平行
    bool is_ver(const Point &a) const { return abs((*this) * a) <= eps; } // 垂直

    int toleft(const Point &a) const {
        auto t = (*this) ^ a;
        return (t > eps) - (t < -eps);
    }

    T len2() const { return (*this) * (*this); }
    T dis2(const Point &a) const { return (a - (*this)).len2(); }
    double len() const { return sqrt(len2()); }
    double dis(const Point &a) const { return (a - (*this)).len(); }
    double ang(const Point &a) const { return acos(((*this) * a) / (this->len() * a.len())); }
    Point rot(const double rad) const { return {x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad)}; }
};

template<typename T>
struct Line {
    Point<T> p, v; //p+kv

    bool operator==(const Line &a) const { return v.is_par(a.v) && v.is_par(p - a.p); }
    bool is_par(const Line &a) const { return v.is_par(a.v) && !v.is_par(p - a.p); } // 排除共线
    bool is_ver(const Line &a) const { return v.is_ver(a.v); }
    bool is_on(const Point<T> &a) const { return v.is_par(a - p); }
    int toleft(const Point<T> &a) const { return v.toleft(a - p); }
    Point<T> inter(const Line &a) const { return p + v * ((a.v ^ (p - a.p)) / (v ^ a.v)); } // 两直线交点
    double dis(const Point<T> &a) const { return abs(v ^ (a - p)) / v.len(); }
    Point<T> proj(const Point<T> &a) const { return p + v * ((v * (a - p)) / (v * v)); }

    bool operator<(const Line &a) const {
        if (abs(v ^ a.v) <= eps && v * a.v >= -eps) return toleft(a.p) == -1;
        return argcmp(v, a.v);
    }
};

template<typename T>
struct Polygon {
    vector<Point<T> > p;

    size_t nxt(const size_t i) const { return i == p.size() - 1 ? 0 : i + 1; }
    size_t pre(const size_t i) const { return i == 0 ? p.size() - 1 : i - 1; }
};

int n;
Polygon<db> poly;
set<pair<Point<db>, Point<db> > > edges;

template<typename T>
db calc(const Line<T> &l) {
    vector<tuple<Point<db>, Point<db>, Point<db> > > vec;
    for (int i = 0; i < n; i++) {
        auto u = poly.p[i], v = poly.p[poly.nxt(i)];
        int c1 = l.toleft(u), c2 = l.toleft(v);
        if (c1 * c2 <= 0) {
            if (c1 == 0 && c2 == 0) {
                vec.emplace_back(u, u, v);
                vec.emplace_back(v, u, v);
            } else {
                auto s = l.inter({u, u - v});
                vec.emplace_back(s, u, v);
            }
        }
    }
    sort(vec.begin(), vec.end());
    int cnt = 0;
    Point pre = {1e12, 1e12};
    db len = 0, maxlen = 0;
    while (!vec.empty()) {
        auto [now,u,v] = vec.back();
        if (cnt || edges.count({now, pre})) {
            len += now.dis(pre);
        } else {
            maxlen = max(maxlen, len);
            len = 0;
        }
        while (!vec.empty() && get<0>(vec.back()) == now) {
            auto [p,u,v] = vec.back();
            vec.pop_back();
            if (l.toleft(u) == -1) cnt++;
            else if (l.toleft(v) == -1) cnt--;
        }
        pre = now;
    }
    return max(maxlen, len);
}

inline void Zlin() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        Point<db> tmp;
        cin >> tmp.x >> tmp.y;
        poly.p.emplace_back(tmp);
    }
    for (int i = 0; i < n; i++) {
        auto u = poly.p[i], v = poly.p[poly.nxt(i)];
        edges.insert({u, v});
        edges.insert({v, u});
    }
    db ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            Line line = {poly.p[i], poly.p[j] - poly.p[i]};
            ans = max(ans, calc(line));
        }
    }
    cout << fixed << setprecision(9) << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
