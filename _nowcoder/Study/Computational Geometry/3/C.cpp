//
// Created by Zlin on 2025/9/12.
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
};

using Point = point<ll>;

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

constexpr int N = 3000;

int n;
vector<Point> a;
Point sum[N];

inline ll cal(Point s) {
    vector<Point> tmp;
    for (int i = 0; i < n; i++) {
        if (a[i] == s || a[i].x < s.x || (a[i].x == s.x && a[i].y < s.y)) continue;
        tmp.emplace_back(a[i] - s);
    }
    sort(tmp.begin(), tmp.end(), argcmp);
    for (int i = 0; i < tmp.size(); i++) {
        if (i) sum[i] = sum[i - 1] + tmp[i];
        else sum[i] = tmp[i];
    }
    ll ans = 0;
    for (int i = 0; i < tmp.size(); i++) ans += tmp[i] ^ (sum[tmp.size() - 1] - sum[i]);
    return ans;
}

inline void Zlin() {
    cin >> n;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        a.emplace_back(x, y);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) ans += cal(a[i]);
    if (ans & 1) cout << ans / 2 << ".5" << endl;
    else cout << ans / 2 << ".0" << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
