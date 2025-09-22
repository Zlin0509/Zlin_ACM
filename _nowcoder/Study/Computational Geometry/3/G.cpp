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
    //     return Point(x * cosr - y * sinr, x * sinr + y * cosr);
    // }
};

using Point = point<double>;

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

struct MyCmp {
    bool operator()(const pair<Point, int> &A, const pair<Point, int> &B) const {
        auto cross = A.first.x * B.first.y - A.first.y * B.first.x;
        if (cross == 0) return A.second < B.second;
        return cross < 0;
    }
};

int n, t;
vector<Point> p;
map<pair<Point, int>, int, MyCmp> cnt;

inline void prework(int idx) {
    map<Point, int, decltype(&argcmp)> mp(&argcmp);
    for (int i = 0; i < n; i++) if (i != idx) mp[p[i] - p[idx]]++;
    vector<Point> tmp;
    for (auto o: mp) tmp.emplace_back(o.first);
    int siz = tmp.size();
    tmp.insert(tmp.end(), tmp.begin(), tmp.end());
    for (int l = 0, r = 0, cnt = 0; l < siz; l++) {
        if (l) cnt -= mp[tmp[l - 1]];
        cnt += mp[tmp[l]];
        while (r < tmp.size() && tmp[l].toleft(tmp[r]) == 1) {
            if (l != r) cnt += mp[tmp[r]];
            ++r;
        }
    }
}

inline int Zlin(int idx) {
    map<Point, int, decltype(&argcmp)> mp(&argcmp);
    for (int i = 0; i < n; i++) if (i != idx) mp[p[i] - p[idx]]++;
    vector<Point> tmp;
    for (auto o: mp) tmp.emplace_back(o.first);
    for (int i = 0; i < tmp.size(); i++) {
    }
}

inline void Zlin() {
    cin >> n >> t;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        p.emplace_back(x, y);
    }
    for (int i = 0; i < n; i++) prework(i);
    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, Zlin(i));
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
