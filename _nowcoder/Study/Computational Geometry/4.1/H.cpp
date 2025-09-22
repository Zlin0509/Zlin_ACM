//
// Created by 27682 on 2025/9/22.
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

using T = long double; //全局数据类型

constexpr T eps = 1e-8;
constexpr T INF = numeric_limits<T>::max();
constexpr T PI = 3.1415926535897932384l;

// 点与向量
struct Point {
    T x, y;

    bool operator==(const Point &a) const { return (abs(x - a.x) <= eps && abs(y - a.y) <= eps); }

    bool operator<(const Point &a) const {
        if (abs(x - a.x) <= eps) return y < a.y - eps;
        return x < a.x - eps;
    }

    bool operator>(const Point &a) const { return !(*this < a || *this == a); }
    Point operator+(const Point &a) const { return {x + a.x, y + a.y}; }
    Point operator-(const Point &a) const { return {x - a.x, y - a.y}; }
    Point operator-() const { return {-x, -y}; }
    Point operator*(const T k) const { return {k * x, k * y}; }
    Point operator/(const T k) const { return {x / k, y / k}; }
    T operator*(const Point &a) const { return x * a.x + y * a.y; } // 点积
    T operator^(const Point &a) const { return x * a.y - y * a.x; } // 叉积，注意优先级
    int toleft(const Point &a) const {
        const auto t = (*this) ^ a;
        return (t > eps) - (t < -eps);
    } // to-left 测试
    T len2() const { return (*this) * (*this); } // 向量长度的平方
    T dis2(const Point &a) const { return (a - (*this)).len2(); } // 两点距离的平方
    int quad() const // 象限判断 0:原点 1:x轴正 2:第一象限 3:y轴正 4:第二象限 5:x轴负 6:第三象限 7:y轴负 8:第四象限
    {
        if (abs(x) <= eps && abs(y) <= eps) return 0;
        if (abs(y) <= eps) return x > eps ? 1 : 5;
        if (abs(x) <= eps) return y > eps ? 3 : 7;
        return y > eps ? (x > eps ? 2 : 4) : (x > eps ? 8 : 6);
    }

    // 必须用浮点数
    T len() const { return sqrtl(len2()); } // 向量长度
    T dis(const Point &a) const { return sqrtl(dis2(a)); } // 两点距离
    T ang(const Point &a) const { return acosl(max(-1.0l, min(1.0l, ((*this) * a) / (len() * a.len())))); } // 向量夹角
    Point rot(const T rad) const { return {x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad)}; } // 逆时针旋转（给定角度）
    Point rot(const T cosr, const T sinr) const { return {x * cosr - y * sinr, x * sinr + y * cosr}; }
    // 逆时针旋转（给定角度的正弦与余弦）
};

// 直线
struct Line {
    Point p, v; // p 为直线上一点，v 为方向向量

    T dis(const Point &a) const { return abs(v ^ (a - p)) / v.len(); } // 点到直线距离
};

// 多边形
struct Polygon {
    vector<Point> p; // 以逆时针顺序存储

    size_t nxt(const size_t i) const { return i == p.size() - 1 ? 0 : i + 1; }
    size_t pre(const size_t i) const { return i == 0 ? p.size() - 1 : i - 1; }
};

T p2seg(const Point &u, const Point &v, const Point &p) {
    Line uv = {u, v - u};
    if ((p - u) * (v - u) >= -eps && (p - v) * (u - v) >= -eps) return uv.dis(p);
    return min(p.dis(u), p.dis(v));
}

//凸多边形
struct Convex : Polygon {
    T rotcaliper(const Convex &b) const {
        const auto &p1 = this->p, &p2 = b.p;
        const auto area = [](const Point &u, const Point &v, const Point &w) { return (w - u) ^ (w - v); };
        T ans = INF;
        int r = 0;
        for (int i = 0; i < p2.size(); i++) if (area(p2[i], p1[0], p1[1]) >= area(p2[r], p1[0], p1[1]) - eps) r = i;
        for (size_t i = 0, j = r; i < p1.size(); i++) {
            const auto nxti = this->nxt(i);
            ans = min(ans, p2seg(p1[i], p1[nxti], p2[j]));
            while (area(p2[b.nxt(j)], p1[i], p1[nxti]) >= area(p2[j], p1[i], p1[nxti]) - eps) {
                j = b.nxt(j);
                ans = min(ans, p2seg(p1[i], p1[nxti], p2[j]));
            }
        }
        return ans;
    }
};

Convex convexhull(vector<Point> p) {
    vector<Point> res;
    if (p.empty()) return Convex{res};
    sort(p.begin(), p.end());
    const auto check = [](const vector<Point> &res, const Point &u) {
        const auto b1 = res.back(), b2 = *prev(res.end(), 2);
        return (b1 - b2).toleft(u - b1) <= 0;
    };
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
    return Convex{res};
}

inline void Zlin(int n, int m) {
    vector<Point> p1, p2;
    for (int i = 0; i < n; i++) {
        T x, y;
        cin >> x >> y;
        p1.emplace_back(x, y);
    }
    for (int i = 0; i < m; i++) {
        T x, y;
        cin >> x >> y;
        p2.emplace_back(x, y);
    }
    Convex c1 = convexhull(p1), c2 = convexhull(p2);
    T ans = min(c1.rotcaliper(c2), c2.rotcaliper(c1));
    cout << fixed << setprecision(9) << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    while (1) {
        int n, m;
        cin >> n >> m;
        if (!n && !m) break;
        Zlin(n, m);
    }
    return 0;
}
