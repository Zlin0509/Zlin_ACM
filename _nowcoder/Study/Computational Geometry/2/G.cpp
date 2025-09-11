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
    double ang(const Point &a) const { return acos(((*this) * a) / (this->len() * a.len())); }
    Point rot(const double rad) const { return {x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad)}; }
};

template<typename T>
bool is_on(const Point<T> p, const Point<T> a, const Point<T> b) {
    return abs((p - a) ^ (p - b)) <= eps && (p - a) * (p - b) <= eps;
}

template<typename T>
bool is_in(const Point<T> p, const Point<T> a, const Point<T> b, const Point<T> c) {
    if (is_on(p, a, b) || is_on(p, b, c) || is_on(p, c, a)) return true;
    if ((b - a).toleft(p - a) > 0 && (c - b).toleft(p - b) > 0 && (a - c).toleft(p - c) > 0) return true;
    if ((b - a).toleft(p - a) < 0 && (c - b).toleft(p - b) < 0 && (a - c).toleft(p - c) < 0) return true;
    return false;
}

Point<db> a, b, c, p;

inline void Zlin() {
    cin >> p.x >> p.y;
    cout << (is_in(p, a, b, c) ? "YES" : "NO") << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
