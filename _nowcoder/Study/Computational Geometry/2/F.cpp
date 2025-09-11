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
    T operator*(const Point &a) const { return x * a.x + y * a.y; } // Dot
    T operator^(const Point &a) const { return x * a.y - y * a.x; } // Cross
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
    Point<T> inter(const Line &a) const { return p + v * ((a.v ^ (p - a.p)) / (v ^ a.v)); }
    double dis(const Point<T> &a) const { return abs(v ^ (a - p)) / v.len(); }
    Point<T> proj(const Point<T> &a) const { return p + v * ((v * (a - p)) / (v * v)); }

    bool operator<(const Line &a) const {
        if (abs(v ^ a.v) <= eps && v * a.v >= -eps) return toleft(a.p) == -1;
        return argcmp(v, a.v);
    }
};

db L, h, sq3;
Line<db> line;
ll k;

inline void Zlin() {
    cin >> L >> line.p.x >> line.p.y >> line.v.x >> line.v.y >> k;
    sq3 = sqrt((db) 3);
    h = sq3 * L / 2;
    db l = 0, r = 1e12, mid, low, high;
    ll cnt, c1, c2;
    for (int i = 1; i <= 600; i++) {
        mid = (l + r) / 2, cnt = 0;
        Point u = line.p, v = u + line.v * mid;
        low = min(u.y, v.y), high = max(u.y, v.y);
        c1 = ceil(low / h), c2 = floor(high / h);
        cnt += c2 - c1 + 1;
        low = min(u.y - sq3 * u.x, v.y - sq3 * v.x), high = max(u.y - sq3 * u.x, v.y - sq3 * v.x);
        c1 = ceil((low - h) / (h * 2)), c2 = floor((high - h) / (h * 2));
        cnt += c2 - c1 + 1;
        low = min(u.y + sq3 * u.x, v.y + sq3 * v.x), high = max(u.y + sq3 * u.x, v.y + sq3 * v.x);
        c1 = ceil((low - h) / (h * 2)), c2 = floor((high - h) / (h * 2));
        cnt += c2 - c1 + 1;
        if (cnt >= k) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(10) << l << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
