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

using T = long long;

constexpr T eps = 1e-9;

struct Point {
    T x, y;

    bool operator<(const Point &other) const {
        if (abs(x - other.x) < eps) return y < other.y - eps;
        return x < other.x - eps;
    }

    bool operator==(const Point &other) const {
        return abs(x - other.x) <= eps && abs(y - other.y) <= eps;
    }

    Point operator-(const Point &other) const { return {x - other.x, y - other.y}; }
    T operator^(const Point &other) const { return x * other.y - y * other.x; }
    T operator*(const Point &other) const { return x * other.x + y * other.y; }

    int toleft(const Point &other) const {
        const auto res = (*this) ^ other;
        return (res > eps) - (res < eps);
    }
};

struct Seg {
    Point a, b;

    bool is_on(const Point &p) const {
        if (p == a || p == b) return -1;
        return (p - a).toleft(p - b) == 0 && (p - a) * (p - b) <= -eps;
    }
};

struct Polygon {
    vector<Point> p;

    size_t nxt(const size_t i) const { return i == p.size() - 1 ? 0 : i + 1; }
    size_t pre(const size_t i) const { return i == 0 ? p.size() - 1 : i - 1; }
};

struct Convex : Polygon {
    int is_in(const Point &a) const {
        const auto &p = this->p;
        if (p.size() == 1) return a == p[0] ? 1 : 0;
        if (p.size() == 2) return Seg(p[0], p[1]).is_on(a) ? -1 : 0;
        if (a == p[0]) return -1;
        if ((p[1] - p[0]).toleft(a - p[0]) == -1 || (p.back() - p[0]).toleft(a - p[0]) == 1) return 0;
        const auto cmp = [&](const Point &u, const Point &v) { return (u - p[0]).toleft(v - p[0]) == 1; };
        const size_t i = lower_bound(p.begin(), p.end(), a, cmp) - p.begin();
        if (i == 1) return Seg(p[0], p[i]).is_on(a) ? -1 : 0;
        if (i == p.size() - 1 && Seg(p[0], p[i]).is_on(a)) return -1;
        if (Seg(p[i - 1], p[i]).is_on(a)) return -1;
        return (p[i] - p[i - 1]).toleft(a - p[i - 1]) > 0;
    }

    template<typename F>
    size_t extreme(const F &dir) const {
        const auto &p = this->p;
        const auto check = [&](const size_t i) { return dir(p[i]).toleft(p[this->nxt(i)] - p[i]) >= 0; };
        const auto dir0 = dir(p[0]);
        const auto check0 = check(0);
        if (!check0 && check(p.size() - 1)) return 0;
        const auto cmp = [&](const Point &v) {
            const size_t vi = &v - p.data();
            if (!vi) return 1;
            const auto checkv = check(vi);
            const auto t = dir0.toleft(v - p[0]);
            if (vi == 1 && checkv == check0 && t == 0) return 1;
            return checkv ^ (checkv == check0 && t <= 0);
        };
        return partition_point(p.begin(), p.end(), cmp) - p.begin();
    }

    pair<size_t, size_t> tangent(const Point &a) const {
        const size_t i = extreme([&](const Point &u) { return u - a; });
        const size_t j = extreme([&](const Point &u) { return a - u; });
        return {i, j};
    }
};

Convex convexhull(vector<Point> p) {
    vector<Point> res;
    if (p.empty()) return {res};
    const auto check = [](const vector<Point> &st, const Point &u) {
        const auto b1 = st.back(), b2 = *prev(st.end(), 2);
        return (b2 - b1).toleft(u - b1) <= 0;
    };
    sort(p.begin(), p.end());
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
    if (res.size() >= 3 && (res[1] - res[0]).toleft(res[2] - res[1]) < 0) reverse(res.begin(), res.end());
    return {res};
}

constexpr int N = 1e5 + 1;

T sum[N + 2]{}, all = 0;

inline T cal(size_t i, size_t j, const Point &u, const vector<Point> &p) {
    T res = 0;
    if (i < j) {
        if ((p[j] - p[i]).toleft(u - p[i]) < 0) {
            res = all - sum[(j >= 1 ? j - 1 : N)] + sum[(i >= 1 ? i - 1 : N)] + (p[i] ^ p[j]);
            res = abs(res) + abs((p[j] ^ u) + (u ^ p[i]) + (p[i] ^ p[j]));
        } else {
            res = sum[(j >= 1 ? j - 1 : N)] - sum[(i >= 1 ? i - 1 : N)] + (p[j] ^ p[i]);
            res = abs(res) + abs((p[j] ^ u) + (u ^ p[i]) + (p[i] ^ p[j]));
        }
    } else {
        if ((p[j] - p[i]).toleft(u - p[i]) < 0) {
            res = sum[(i >= 1 ? i - 1 : N)] - sum[(j >= 1 ? j - 1 : N)] + (p[i] ^ p[j]);
            res = abs(res) + abs((p[j] ^ u) + (u ^ p[i]) + (p[i] ^ p[j]));
        } else {
            res = all - sum[(i >= 1 ? i - 1 : N)] + sum[(j >= 1 ? j - 1 : N)] + (p[j] ^ p[i]);
            res = abs(res) + abs((p[j] ^ u) + (u ^ p[i]) + (p[i] ^ p[j]));
        }
    }
    return res;
}

inline void Zlin() {
    int n, k;
    cin >> n >> k;
    vector<Point> v;
    Convex poly;
    for (int i = 0; i < n; i++) {
        T x, y;
        cin >> x >> y;
        if (i < k) poly.p.emplace_back(x, y);
        else v.emplace_back(x, y);
    }
    poly = convexhull(poly.p);
    size_t siz = poly.p.size();
    for (int i = 0; i < siz; i++) {
        size_t nxti = poly.nxt(i);
        sum[i] = poly.p[i] ^ poly.p[nxti];
        if (i) sum[i] += sum[i - 1];
    }
    all = sum[siz - 1];
    T ans = abs(all);
    for (const auto &u: v) {
        if (poly.is_in(u) != 0) continue;
        auto [i, j] = poly.tangent(u);
        ans = max(ans, cal(i, j, u, poly.p));
    }
    cout << ans / 2;
    if (ans & 1) cout << ".5";
    else cout << ".0";
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
