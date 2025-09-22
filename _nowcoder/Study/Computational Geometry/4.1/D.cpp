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

using T = double; //全局数据类型

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
    Point rot(const T rad) const { return {x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad)}; } // 逆时针旋转（给定角度）
    Point rot(const T cosr, const T sinr) const { return {x * cosr - y * sinr, x * sinr + y * cosr}; }
    // 逆时针旋转（给定角度的正弦与余弦）
};

// 极角排序
struct Argcmp {
    bool operator()(const Point &a, const Point &b) const {
        const int qa = a.quad(), qb = b.quad();
        if (qa != qb) return qa < qb;
        const auto t = a ^ b;
        // if (abs(t)<=eps) return a*a<b*b-eps;  // 不同长度的向量需要分开
        return t > eps;
    }
};

// 直线
struct Line {
    Point p, v; // p 为直线上一点，v 为方向向量

    bool operator==(const Line &a) const { return v.toleft(a.v) == 0 && v.toleft(p - a.p) == 0; }
    int toleft(const Point &a) const { return v.toleft(a - p); } // to-left 测试
    bool operator<(const Line &a) const // 半平面交算法定义的排序
    {
        if (abs(v ^ a.v) <= eps && v * a.v >= -eps) return toleft(a.p) == -1;
        return Argcmp()(v, a.v);
    }

    // 必须用浮点数
    Point inter(const Line &a) const { return p + v * ((a.v ^ (p - a.p)) / (v ^ a.v)); } // 直线交点
    T dis(const Point &a) const { return abs(v ^ (a - p)) / v.len(); } // 点到直线距离
    Point proj(const Point &a) const { return p + v * ((v * (a - p)) / (v * v)); } // 点在直线上的投影
};

// 多边形
struct Polygon {
    vector<Point> p; // 以逆时针顺序存储

    size_t nxt(const size_t i) const { return i == p.size() - 1 ? 0 : i + 1; }
    size_t pre(const size_t i) const { return i == 0 ? p.size() - 1 : i - 1; }

    // 多边形面积的两倍
    // 可用于判断点的存储顺序是顺时针或逆时针
    T area() const {
        T sum = 0;
        for (size_t i = 0; i < p.size(); i++) sum += p[i] ^ p[nxt(i)];
        return abs(sum) / 2;
    }
};

Polygon convexhull(vector<Point> p) {
    vector<Point> res;
    if (p.empty()) return Polygon{res};
    sort(p.begin(), p.end());
    const auto check = [&](const vector<Point> &res, const Point &u) {
        const auto b1 = res.back(), b2 = *prev(res.end(), 2);
        return (b1 - b2).toleft(u - b1) <= 0;
    };
    for (const Point &u: p) {
        while (res.size() > 1 && check(res, u)) res.pop_back();
        res.emplace_back(u);
    }
    int siz = res.size();
    res.pop_back();
    reverse(p.begin(), p.end());
    for (const Point &u: p) {
        while (res.size() > siz && check(res, u)) res.pop_back();
        res.emplace_back(u);
    }
    res.pop_back();
    return Polygon{res};
}

Polygon rotcaliper(Polygon &a) {
    T ans = INF;
    Polygon res;
    const auto area = [](const Point &u, const Point &v, const Point &w) { return (w - u) ^ (w - v); };
    for (int i = 0, j = 1, lx = -1, rx = -1; i < a.p.size(); i++) {
        int nxti = a.nxt(i), nxtj = a.nxt(j);
        while (area(a.p[j], a.p[i], a.p[nxti]) <= area(a.p[nxtj], a.p[i], a.p[nxti])) {
            j = nxtj;
            nxtj = a.nxt(j);
        }
        if (lx == -1) lx = i, rx = j;
        Point v(a.p[nxti] - a.p[i]);
        v = Point(-v.y, v.x);
        while (v.toleft(a.p[a.nxt(lx)] - a.p[lx]) <= 0) lx = a.nxt(lx);
        while (v.toleft(a.p[a.nxt(rx)] - a.p[rx]) >= 0) rx = a.nxt(rx);
        Line li(a.p[i], a.p[a.nxt(i)] - a.p[i]), lj(a.p[j], a.p[i] - a.p[a.nxt(i)]);
        Line ll(a.p[lx], v), lr(a.p[rx], v);
        vector t = {li.inter(ll), ll.inter(lj), lj.inter(lr), lr.inter(li)};
        Polygon pl(t);
        T tmp = pl.area();
        if (tmp < ans) ans = tmp, res = pl;
    }
    return res;
}

inline void Zlin() {
    int n;
    cin >> n;
    vector<Point> p;
    for (int i = 0; i < n; i++) {
        T x, y;
        cin >> x >> y;
        p.emplace_back(x, y);
    }
    Polygon poly = convexhull(p);
    poly = rotcaliper(poly);
    cout << fixed << setprecision(6) << poly.area() << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
