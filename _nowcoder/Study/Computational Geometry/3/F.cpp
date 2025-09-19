//
// Created by Zlin on 2025/9/15.
//

#include <complex>

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


    point rot(const long double &sinr) const {
        const long double cosr = sqrt(1 - sinr * sinr);
        return Point(x * cosr - y * sinr, x * sinr + y * cosr);
    }
};

using Point = point<ll>;

bool is_on(const Point p, const Point a, const Point b) {
    return abs((p - a) ^ (p - b)) <= eps && (p - a) * (p - b) <= eps;
}

bool argcmp(const Point &a, const Point &b) {
    auto quad = [](const Point &a) {
        if (a.y < -eps) return 1;
        if (a.y > eps) return 4;
        if (a.x > eps) return 3;
        if (a.x < -eps) return 5;
        return 2;
    };
    int x = quad(a), y = quad(b);
    if (x != y) return x < y;
    auto res = a ^ b;
    // if (abs(res) < eps) return a * a < b * b - eps; // 相同位置按距离原点长度排序
    return res > eps;
}

constexpr int N = 1000;

int n, ans, c[N], sum[2];
vector<Point> p;

inline int solve(int idx) {
    vector<pair<Point, int> > tmp;
    for (int i = 0; i < n; i++) {
        if (i == idx) continue;
        tmp.emplace_back(p[i] - p[idx], c[i]);
    }
    map<Point, array<int, 2>, decltype(&argcmp)> cnt(&argcmp);
    for (auto [p, r]: tmp) cnt[p][r]++;
    vector<pair<Point, array<int, 2> > > a;
    for (auto it: cnt) a.emplace_back(it);
    int siz = a.size();
    a.insert(a.end(), a.begin(), a.end());
    int cntl[2]{}, ans = 1;
    for (int l = 0, r = 0; l < siz; l++) {
        if (l && a[l].first.toleft(a[l - 1].first) == -1) {
            cntl[0] -= a[l].second[0];
            cntl[1] -= a[l].second[1];
        }
        while (r < a.size() && (l == r || a[l].first.toleft(a[r].first) == 1)) {
            if (l != r) {
                cntl[0] += a[r].second[0];
                cntl[1] += a[r].second[1];
            }
            ++r;
        }
        int cntr[2]{}, cnto[2]{};
        cnto[0] = a[l].second[0];
        cnto[1] = a[l].second[1];
        cnto[c[idx]]++;
        if (r < a.size() && a[l].first != a[r].first && !a[l].first.toleft(a[r].first)) {
            cnto[0] += a[r].second[0];
            cnto[1] += a[r].second[1];
        }
        cntr[0] = sum[0] - cntl[0] - cnto[0];
        cntr[1] = sum[1] - cntl[1] - cnto[1];
        ans = max({ans, cnto[0] + cnto[1] + cntl[0] + cntr[1], cnto[0] + cnto[1] + cntl[1] + cntr[0]});
    }
    return ans;
}

inline void Zlin(int _n) {
    n = _n;
    ans = sum[0] = sum[1] = 0;
    p.clear();
    for (int i = 0, x, y, r; i < n; i++) {
        cin >> x >> y >> r;
        p.emplace_back(x, y);
        c[i] = r;
        ++sum[r];
    }
    for (int i = 0; i < n; i++) ans = max(ans, solve(i));
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (1) {
        cin >> ttt;
        if (!ttt) break;
        Zlin(ttt);
    }
    return 0;
}
