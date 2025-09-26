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

//线段
struct Segment {
    Point a, b;

    bool operator<(const Segment &s) const { return make_pair(a, b) < make_pair(s.a, s.b); }

    // 判定性函数建议在整数域使用

    // 判断点是否在线段上
    // -1 点在线段端点 | 0 点不在线段上 | 1 点严格在线段上
    int is_on(const Point &p) const {
        if (p == a || p == b) return -1;
        return (p - a).toleft(p - b) == 0 && (p - a) * (p - b) < -eps;
    }
};

// 多边形
struct Polygon {
    vector<Point> p; // 以逆时针顺序存储

    size_t nxt(const size_t i) const { return i == p.size() - 1 ? 0 : i + 1; }
    size_t pre(const size_t i) const { return i == 0 ? p.size() - 1 : i - 1; }
};

//凸多边形
struct Convex : Polygon {
    // 判断点是否在凸多边形内
    // 复杂度 O(logn)
    // -1 点在多边形边上 | 0 点在多边形外 | 1 点在多边形内
    int is_in(const Point &a) const {
        const auto &p = this->p;
        if (p.size() == 1) return a == p[0] ? -1 : 0;
        if (p.size() == 2) return Segment{p[0], p[1]}.is_on(a) ? -1 : 0;
        if (a == p[0]) return -1;
        if ((p[1] - p[0]).toleft(a - p[0]) == -1 || (p.back() - p[0]).toleft(a - p[0]) == 1) return 0;
        const auto cmp = [&](const Point &u, const Point &v) { return (u - p[0]).toleft(v - p[0]) == 1; };
        const size_t i = lower_bound(p.begin() + 1, p.end(), a, cmp) - p.begin();
        if (i == 1) return Segment{p[0], p[i]}.is_on(a) ? -1 : 0;
        if (i == p.size() - 1 && Segment{p[0], p[i]}.is_on(a)) return -1;
        if (Segment{p[i - 1], p[i]}.is_on(a)) return -1;
        return (p[i] - p[i - 1]).toleft(a - p[i - 1]) > 0;
    }
};

inline void Zlin() {
    int n;
    cin >> n;
    Convex a;
    for (int i = 0; i < n; i++) {
        T x, y;
        cin >> x >> y;
        a.p.emplace_back(x, y);
    }
    int m;
    cin >> m;
    Convex b;
    for (int i = 0; i < m; i++) {
        T x, y;
        cin >> x >> y;
        b.p.emplace_back(x, y);
    }
    sort(a.p.begin(), a.p.end(), Argcmp());
    sort(b.p.begin(), b.p.end(), Argcmp());
    for (const auto &u: b.p) {
        if (a.is_in(u) != 1) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}


signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
