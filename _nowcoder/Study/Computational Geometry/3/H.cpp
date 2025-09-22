//
// Created by Zlin on 2025/9/22.
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
struct point {
    T x, y;

    bool operator==(const point &a) const { return (abs(x - a.x) <= eps && abs(y - a.y) <= eps); }
    point operator+(const point &a) const { return {x + a.x, y + a.y}; }
    point operator-(const point &a) const { return {x - a.x, y - a.y}; }
    point operator-() const { return {-x, -y}; }
    point operator*(const T k) const { return {k * x, k * y}; }
    point operator/(const T k) const { return {x / k, y / k}; }
    T operator*(const point &a) const { return x * a.x + y * a.y; } // Dot
    T operator^(const point &a) const { return x * a.y - y * a.x; } // Cross
    bool operator<(const point &a) const {
        if (abs(x - a.x) <= eps) return y < a.y - eps;
        return x < a.x - eps;
    }

    bool is_par(const point &a) const { return abs((*this) ^ a) <= eps; } // 平行
    bool is_ver(const point &a) const { return abs((*this) * a) <= eps; } // 垂直

    int toleft(const point &a) const {
        auto t = (*this) ^ a;
        return (t > eps) - (t < -eps);
    }


    T len2() const { return (*this) * (*this); }
    T dis2(const point &a) const { return (a - (*this)).len2(); }
    double len() const { return sqrt(len2()); }
    double dis(const point &a) const { return (a - (*this)).len(); }
    double ang(const point &a) const { return acos(((*this) * a) / (this->len() * a.len())); } // 普通夹角（只返回大小 [0, π]）
    double signed_ang(const point &a) const { return atan2((*this) ^ a, (*this) * a); } // 带方向夹角：逆时针为正，顺时针为负，范围 (-π, π]
    point rot(const double rad) const { return {x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad)}; }


    // point rot(const long double &sinr) const {
    //     const long double cosr = sqrt(1 - sinr * sinr);
    //     return point(x * cosr - y * sinr, x * sinr + y * cosr);
    // }
};

using Point = point<double>;

int n;
Point tmp[55];
vector<Point> p;

inline void solve(int idx) {
    vector<double> tag;
    for (int i = 0; i < n; i++) {
        if (i == idx) continue;
        for (int j = i + 1; j < n; j++) {
            if (j == idx) continue;
            auto l = p[i], r = p[j];
            double res = atan2(l.x - r.x, l.y - r.y);
            tag.emplace_back(res);
            if (res > eps) tag.emplace_back(res - pi);
            if (res < -eps) tag.emplace_back(res + pi);
            res = atan2(l.x + r.x - p[idx].x * 2, l.y + r.y - p[idx].y * 2);
            tag.emplace_back(res);
            if (res > eps) tag.emplace_back(res - pi);
            if (res < -eps) tag.emplace_back(res + pi);
        }
    }
    tag.emplace_back(-pi), tag.emplace_back(pi);
    sort(tag.begin(), tag.end());
    vector ans(n, 0.0);
    for (int i = 1; i < tag.size(); i++) {
        double rot = (tag[i - 1] + tag[i]) / 2;
        for (int j = 0; j < n; j++) tmp[j] = p[j].rot(rot);
        int id = -1;
        double mx = 1e12;
        for (int j = 0; j < n; j++) {
            if (j != idx && fabs(tmp[j].x - tmp[idx].x) < mx - eps) {
                mx = fabs(tmp[j].x - tmp[idx].x);
                id = j;
            }
        }
        ans[id] += tag[i] - tag[i - 1];
    }
    for (int i = 0; i < n; i++) cout << fixed << setprecision(9) << ans[i] / pi / 2 << ' ';
    cout << endl;
}

inline void Zlin() {
    cin >> n;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        p.emplace_back(x, y);
    }
    for (int i = 0; i < n; i++) solve(i);
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
