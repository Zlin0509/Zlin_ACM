//
// Created by Zlin on 2025/10/26.
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

struct Point {
    T x, y;

    bool operator==(const Point &a) const { return (abs(x - a.x) <= eps && abs(y - a.y) <= eps); }
    Point operator+(const Point &a) const { return {x + a.x, y + a.y}; }
    Point operator-(const Point &a) const { return {x - a.x, y - a.y}; }
    Point operator-() const { return {-x, -y}; }
    T operator*(const Point &a) const { return x * a.x + y * a.y; } // 点积
    T operator^(const Point &a) const { return x * a.y - y * a.x; } // 叉积，注意优先级
    int toleft(const Point &a) const {
        const auto t = (*this) ^ a;
        return (t > eps) - (t < -eps);
    } // to-left 测试
};

struct Polygon {
    vector<Point> p; // 以逆时针顺序存储

    int nxt(const size_t i) const { return i == p.size() - 1 ? 0 : i + 1; }
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

    pii tangent(const Point &a) const {
        int i = extreme([&](const Point &u) { return u - a; });
        int j = extreme([&](const Point &u) { return a - u; });
        return {i, j};
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
    vector<pii> tag(n), dif(n);
    for (int i = 0; i < n; i++) tag[i] = b.tangent(a.p[i]);
    for (int i = 0, j1 = 0, j2 = 0; i < a.p.size(); i++) {
        while ((a.p[a.nxt(j1)] - a.p[i]).toleft(b.p[tag[i].second] - a.p[i]) >= 0) j1 = a.nxt(j1);
        while ((a.p[a.nxt(j2)] - a.p[i]).toleft(b.p[tag[i].first] - a.p[i]) > 0) j2 = a.nxt(j2);
        if ((a.p[j2] - a.p[i]).toleft(b.p[tag[i].first] - a.p[i]) > 0) j2 = a.nxt(j2);
        if ((a.p[j1] - a.p[i]).toleft(a.p[j2] - a.p[i]) < 0) swap(j1, j2);
        dif[i] = {j1, j2};
    }
    auto p = a.p;
    p.insert(p.end(), p.begin(), p.end());
    const auto len = [](int l1, int r1, int l2, int r2, int n) {
        auto seg = [&](int l, int r) -> vector<pair<int, int> > {
            if (l <= r) return {{l, r}};
            return {{l, n - 1}, {0, r}};
        };
        auto f = [&](int L1, int R1, int L2, int R2) {
            int L = max(L1, L2), R = min(R1, R2);
            return max(0, R - L + 1);
        };
        int ans = 0;
        for (auto [a, b]: seg(l1, r1))
            for (auto [c, d]: seg(l2, r2))
                ans += f(a, b, c, d);
        return ans;
    };
    ll cnt = 0, ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
        int lx1 = i, rx1 = dif[i].first;
        int lx2 = dif[i].second, rx2 = i;
        if (j != dif[i].first) {
            do {
                j = a.nxt(j);
                int lx3 = j, rx3 = dif[j].first;
                cnt += len(lx3, rx3, lx2, rx2, n);
            } while (j != dif[i].first);
        }
        ans += cnt;
        if (i != n - 1 && lx2 != dif[i + 1].second) {
            do {
                int lx3 = dif[lx2].second, rx3 = lx2;
                cnt -= len(lx3, rx3, lx1, rx1, n);
                lx2 = a.nxt(lx2);
            } while (lx2 != dif[i + 1].second);
        }
    }
    cout << ans / 3 << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
