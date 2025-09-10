//
// Created by 27682 on 2025/9/10.
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

struct Point {
    db x, y;
} h[1010];

using Vector = Point;

inline db dot(const Vector &a, const Vector &b) {
    return a.x * b.x + a.y * b.y;
}

inline db cross(const Vector &a, const Vector &b) {
    return a.x * b.y - a.y * b.x;
}

inline Vector operator+(const Point &a, const Point &b) {
    return Vector{a.x + b.x, a.y + b.y};
}

inline Vector operator-(const Point &a, const Point &b) {
    return Vector{a.x - b.x, a.y - b.y};
}

inline Vector operator*(const Vector &a, const db &b) {
    return Vector{a.x * b, a.y * b};
}

struct Seg {
    Point a, b;
} t;

struct Line {
    Point p;
    Vector v;
};

inline Point l_to_l(const Line &l1, const Line &l2) {
    Vector w = l2.p - l1.p; // P2 - P1
    db denom = cross(l1.v, l2.v);
    if (fabs(denom) < 1e-9) return {1e18, 1e18};
    db t = cross(w, l2.v) / denom;
    return {l1.p.x + t * l1.v.x, l1.p.y + t * l1.v.y};
}

// 射线 r 与线段 s 是否相交
inline db r_to_s(const Line &r, const Seg &s) {
    Vector d = r.v; // 射线方向
    Vector v = s.b - s.a; // 线段方向
    Vector w = r.p - s.a; // 射线起点到线段起点向量

    db denom = cross(v, d);
    if (fabs(denom) < eps) return -10;

    db t = cross(w, v) / denom;
    db u = cross(w, d) / denom;

    if (t >= -eps && u >= -eps && u <= 1 + eps) return u;
    return -10;
}

int n, m;
vector<db> s[1010];

inline void Zlin() {
    cin >> n >> m >> t.a.x >> t.a.y >> t.b.x >> t.b.y;
    for (int i = 1; i <= n; i++) cin >> h[i].x >> h[i].y;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            Line r = {h[i], h[j] - h[i]};
            db ans = r_to_s(r, t);
            if (ans < 0) continue;
            s[i].emplace_back(ans);
            s[j].emplace_back(ans);
        }
    }
    for (int i = 1; i <= n; i++) sort(s[i].begin(), s[i].end());
    while (m--) {
        int i, k;
        cin >> i >> k;
        if (s[i].size() < k) cout << -1 << endl;
        else {
            Point ans = t.a + (t.b - t.a) * s[i][k - 1];
            cout << fixed << setprecision(9) << ans.x << ' ' << ans.y << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
