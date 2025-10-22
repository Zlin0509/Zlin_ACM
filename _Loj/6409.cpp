//
// Created by Zlin on 2025/10/20.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

using T = ldb;

constexpr ldb eps = 1e-9;

struct Point {
    T x, y;

    bool operator==(const Point &a) const { return fabs(x - a.x) < eps && fabs(y - a.y) < eps; }
    Point operator+(const Point &a) const { return {x + a.x, y + a.y}; }
    Point operator-(const Point &a) const { return {x - a.x, y - a.y}; }
    Point operator-(const T &k) const { return {x * k, y * k}; }
    T operator*(const Point &a) const { return x * a.x + y * a.y; }
    T operator^(const Point &a) const { return x * a.y - y * a.x; }
    Point operator*(const T k) const { return {k * x, k * y}; }

    int toleft(const Point &a) const {
        T t = (*this) ^ a;
        return (t > eps) - (t < -eps);
    }

    int quad() const // 象限判断 0:原点 1:x轴正 2:第一象限 3:y轴正 4:第二象限 5:x轴负 6:第三象限 7:y轴负 8:第四象限
    {
        if (abs(x) <= eps && abs(y) <= eps) return 0;
        if (abs(y) <= eps) return x > eps ? 1 : 5;
        if (abs(x) <= eps) return y > eps ? 3 : 7;
        return y > eps ? (x > eps ? 2 : 4) : (x > eps ? 8 : 6);
    }

    T len2() const { return (*this) * (*this); } // 向量长度的平方
    T len() const { return sqrtl(len2()); } // 向量长度
    T dis2(const Point &a) const { return (a - (*this)).len2(); }
    T dis(const Point &a) const { return sqrtl(dis2(a)); }
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

struct Line {
    Point p, v;

    bool operator<(const Line &a) const // 半平面交算法定义的排序
    {
        if (abs(v ^ a.v) <= eps && v * a.v >= -eps) return toleft(a.p) == -1;
        return Argcmp()(v, a.v);
    }

    int toleft(const Point &a) const { return v.toleft(a - p); }
    Point inter(const Line &a) const { return p + v * ((a.v ^ (p - a.p)) / (v ^ a.v)); } // 直线交点
    T dis(const Point &a) const { return abs(v ^ (a - p)) / v.len(); } // 点到直线距离
};

struct Seg {
    Point a, b;

    int is_on(const Point &p) const {
        if (p == a || p == b) return -1;
        return (p - a).toleft(p - b) == 0 && (p - a) * (p - b) < -eps;
    }

    int is_inter(const Seg &s) const {
        if (is_on(s.a) || is_on(s.b) || s.is_on(a) || s.is_on(b)) return -1;
        const Line l{a, b - a}, ls{s.a, s.b - s.a};
        return l.toleft(s.a) * l.toleft(s.b) == -1 && ls.toleft(a) * ls.toleft(b) == -1;
    }
};

struct Poly {
    vector<Point> p;

    size_t nxt(size_t i) const { return i == p.size() - 1 ? 0 : i + 1; }

    pair<bool, int> winding(const Point &a) const {
        int cnt = 0;
        for (size_t i = 0; i < p.size(); i++) {
            const Point u = p[i], v = p[nxt(i)];
            if (abs((a - u) ^ (a - v)) <= eps && (a - u) * (a - v) <= eps) return {true, 0};
            if (abs(u.y - v.y) <= eps) continue;
            const Line uv = {u, v - u};
            if (u.y < v.y - eps && uv.toleft(a) <= 0) continue;
            if (u.y > v.y + eps && uv.toleft(a) >= 0) continue;
            if (u.y < a.y - eps && v.y >= a.y - eps) cnt++;
            if (u.y >= a.y - eps && v.y < a.y - eps) cnt--;
        }
        return {false, cnt};
    }
};

// 半平面交
// 排序增量法，复杂度 O(nlogn)
// 输入与返回值都是用直线表示的半平面集合
vector<Line> halfinter(vector<Line> l, const T lim = 1e9) {
    const auto check = [](const Line &a, const Line &b, const Line &c) { return a.toleft(b.inter(c)) < 0; };
    // 无精度误差的方法，但注意取值范围会扩大到三次方
    /*const auto check=[](const Line &a,const Line &b,const Line &c)
    {
        const Point p=a.v*(b.v^c.v),q=b.p*(b.v^c.v)+b.v*(c.v^(b.p-c.p))-a.p*(b.v^c.v);
        return p.toleft(q)<0;
    };*/
    l.push_back({{-lim, 0}, {0, -1}});
    l.push_back({{0, -lim}, {1, 0}});
    l.push_back({{lim, 0}, {0, 1}});
    l.push_back({{0, lim}, {-1, 0}});
    sort(l.begin(), l.end());
    deque<Line> q;
    for (size_t i = 0; i < l.size(); i++) {
        if (i > 0 && l[i - 1].v.toleft(l[i].v) == 0 && l[i - 1].v * l[i].v > eps) continue;
        while (q.size() > 1 && check(l[i], q.back(), q[q.size() - 2])) q.pop_back();
        while (q.size() > 1 && check(l[i], q[0], q[1])) q.pop_front();
        if (!q.empty() && q.back().v.toleft(l[i].v) <= 0) return vector<Line>();
        q.push_back(l[i]);
    }
    while (q.size() > 1 && check(q[0], q.back(), q[q.size() - 2])) q.pop_back();
    while (q.size() > 1 && check(q.back(), q[0], q[1])) q.pop_front();
    return vector<Line>(q.begin(), q.end());
}

inline void Zlin() {
    int n;
    cin >> n;
    Poly poly;
    for (int i = 0; i < n; i++) {
        T x, y;
        cin >> x >> y;
        poly.p.emplace_back(x, y);
    }
    const auto &p = poly.p;
    ldb ans = 0;
    for (int i = 0; i < n; i++) {
        vector<Line> l;
        Point t1, t2;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            t1 = (p[i] + p[j]) * 0.5;
            t2 = Point(p[i].y - p[j].y, p[j].x - p[i].x);
            l.emplace_back(t1, t2);
        }
        l = halfinter(l);
        int m = l.size();
        vector<Point> v;
        for (int j = 0; j < m; j++) {
            const Point tmp = l[j].inter(l[(j + 1) % m]);
            v.emplace_back(tmp);
            if (poly.winding(tmp).second) ans = max(ans, p[i].dis(tmp));
        }
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                Seg s(v[j], v[(j + 1) % m]), t(p[k], p[(k + 1) % n]);
                if (s.is_inter(t)) {
                    Line l1(v[j], v[(j + 1) % m] - v[j]), l2(p[k], p[(k + 1) % n] - p[k]);
                    ans = max(ans, l1.inter(l2).dis(p[i]));
                }
            }
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
