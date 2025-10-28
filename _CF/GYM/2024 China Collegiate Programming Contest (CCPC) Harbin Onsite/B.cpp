//
// Created by 27682 on 2025/10/28.
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

using T = ll; //全局数据类型

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
};

// 直线
struct Line {
    Point p, v; // p 为直线上一点，v 为方向向量
};

// 多边形
struct Polygon {
    vector<Point> p; // 以逆时针顺序存储

    size_t nxt(const size_t i) const { return i == p.size() - 1 ? 0 : i + 1; }
    size_t pre(const size_t i) const { return i == 0 ? p.size() - 1 : i - 1; }

    T area() const {
        T sum = 0;
        for (size_t i = 0; i < p.size(); i++) sum += p[i] ^ p[nxt(i)];
        return abs(sum);
    }
};

struct Convex : Polygon {
    template<typename F>
    size_t extreme(const F &dir) const {
        const auto &p = this->p;
        const auto check = [&](const size_t i) { return dir(p[i]).toleft(p[this->nxt(i)] - p[i]) >= 0; };
        const auto dir0 = dir(p[0]);
        const auto check0 = check(0);
        if (!check0 && check(p.size() - 1)) return 0;
        const auto cmp = [&](const Point &v) {
            const size_t vi = &v - p.data();
            if (vi == 0) return 1;
            const auto checkv = check(vi);
            const auto t = dir0.toleft(v - p[0]);
            if (vi == 1 && checkv == check0 && t == 0) return 1;
            return checkv ^ (checkv == check0 && t <= 0);
        };
        return partition_point(p.begin(), p.end(), cmp) - p.begin();
    }

    pair<size_t, size_t> tangent(const Line &a) const {
        const size_t i = extreme([&](...) { return a.v; });
        const size_t j = extreme([&](...) { return -a.v; });
        return {i, j};
    }
};

Convex convexhull(vector<Point> p) {
    vector<Point> st;
    if (p.empty()) return Convex{st};
    sort(p.begin(), p.end());
    const auto check = [](const vector<Point> &st, const Point &u) {
        const auto back1 = st.back(), back2 = *prev(st.end(), 2);
        return (back1 - back2).toleft(u - back1) <= 0;
    };
    for (const Point &u: p) {
        while (st.size() > 1 && check(st, u)) st.pop_back();
        st.push_back(u);
    }
    size_t k = st.size();
    p.pop_back();
    reverse(p.begin(), p.end());
    for (const Point &u: p) {
        while (st.size() > k && check(st, u)) st.pop_back();
        st.push_back(u);
    }
    st.pop_back();
    return Convex{st};
}

map<Point, bool> tag;

inline void Zlin() {
    int n;
    cin >> n;
    vector<Point> p, tmp;
    for (int i = 0; i < n; i++) {
        T x, y;
        cin >> x >> y;
        p.emplace_back(x, y);
    }
    Convex c1 = convexhull(p);
    tag.clear();
    for (const auto &it: c1.p) tag[it] = true;
    for (const auto &it: p) if (!tag[it]) tmp.emplace_back(it);
    if (tmp.empty()) {
        cout << -1 << endl;
        return;
    }
    ll ans = c1.area(), area = INF;
    if (tmp.size() < 3) {
        for (int i = 0, nxti; i < c1.p.size(); i++) {
            nxti = c1.nxt(i);
            for (const auto &it: tmp) area = min(area, abs(c1.p[nxti] - it ^ c1.p[i] - it));
        }
    } else {
        Convex c2 = convexhull(tmp);
        for (int i = 0, nxti; i < c1.p.size(); i++) {
            nxti = c1.nxt(i);
            auto [x, y] = c2.tangent(Line(c1.p[i], c1.p[nxti] - c1.p[i]));
            area = min({
                area, abs(c1.p[nxti] - c2.p[x] ^ c1.p[i] - c2.p[x]), abs(c1.p[nxti] - c2.p[y] ^ c1.p[i] - c2.p[y])
            });
        }
    }
    cout << ans - area << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
