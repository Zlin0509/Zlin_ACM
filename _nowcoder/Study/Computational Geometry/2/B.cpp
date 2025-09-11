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
const db pi = acos(-1);

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
    Point rot(const double rad) const { return {x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad)}; }
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

template<typename T>
struct Polygon {
    vector<Point<T> > p;

    size_t nxt(const size_t i) const { return i == p.size() - 1 ? 0 : i + 1; }
    size_t pre(const size_t i) const { return i == 0 ? p.size() - 1 : i - 1; }

    pair<bool, int> winding(const Point<T> &a) const {
        int cnt = 0;
        for (size_t i = 0; i < p.size(); i++) {
            Point<T> u = p[i], v = p[nxt(i)];
            if (is_on(a, u, v)) return {true, 0};
            if (abs(u.y - v.y) <= eps) continue;
            Line<T> uv = {u, v - u};
            if (u.y < v.y - eps && uv.toleft(a) <= 0) continue;
            if (u.y > v.y + eps && uv.toleft(a) >= 0) continue;
            if (u.y < a.y - eps && v.y >= a.y - eps) cnt++;
            if (u.y >= a.y - eps && v.y < a.y - eps) cnt--;
        }
        return {false, cnt};
    }
};

constexpr int N = 5000;

int n, m;
Point<db> p;
Polygon<db> poly;

inline void Zlin() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p.x >> p.y;
        poly.p.emplace_back(p);
    }
    cin >> m;
    while (m--) {
        cin >> p.x >> p.y;
        auto ans = poly.winding(p);
        if (ans.first) cout << "EDGE" << endl;
        else cout << ans.second << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
