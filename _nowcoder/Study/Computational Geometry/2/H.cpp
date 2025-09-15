//
// Created by 27682 on 2025/9/11.
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
    double ang(const Point &a) const { return acos(((*this) * a) / (this->len() * a.len())); } // 普通夹角（只返回大小 [0, π]）
    double signed_ang(const Point &a) const { return atan2((*this) ^ a, (*this) * a); } // 带方向夹角：逆时针为正，顺时针为负，范围 (-π, π]
    Point rot(const double &rad) const { return {x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad)}; }

    Point rot(const long double &sinr) const {
        const long double cosr = sqrt(1 - sinr * sinr);
        return Point(x * cosr - y * sinr, x * sinr + y * cosr);
    }
};

template<typename T>
bool is_on(const Point<T> p, const Point<T> a, const Point<T> b) {
    return abs((p - a) ^ (p - b)) <= eps && (p - a) * (p - b) <= eps;
}

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

constexpr int N = 50;

int n;
vector<Point<db> > a;

inline bool check(db d, Line<db> l, Line<db> r) {
    Point<db> lx(1e12, 1e12), rx(-1e12, -1e12);
    bool check = true;
    for (auto s: a) {
        if (l.v.toleft(s - l.p) * r.v.toleft(s - r.p) < eps) continue;
        auto sx = l.proj(s);
        lx = min(lx, sx);
        rx = max(rx, sx);
        check = false;
    }
    return lx.dis(rx) <= d + eps || check;
}

inline bool check(db d, Point<db> a, Point<db> b) {
    long double len = a.dis(b);
    Point v = a - b;
    if (len < d + eps) {
        v = {-v.y, v.x};
        return check(d, Line(a, v), Line(b, v));
    }
    long double sinx = d / len;
    v = (a - b).rot(sinx);
    if (check(d, Line(a, v), Line(b, v))) return true;
    v = (a - b).rot(-sinx);
    if (check(d, Line(a, v), Line(b, v))) return true;
    return false;
}

inline bool check(db d) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (check(d, a[i], a[j])) return true;
        }
    }
    return false;
}

inline void Zlin() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        db x, y;
        cin >> x >> y;
        a.emplace_back(x, y);
    }
    db l = 0, r = 5e5, mid;
    while (fabs(r - l) > eps) {
        mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(9) << l << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
