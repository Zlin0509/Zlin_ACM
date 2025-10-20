//
// Created by Zlin on 2025/10/19.
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

constexpr int N = 7000;

using T = long long; //全局数据类型

struct Point {
    T x, y;

    bool operator<(const Point &a) const {
        if (abs(x - a.x) == 0) return y < a.y;
        return x < a.x;
    }

    Point operator-(const Point &a) const {
        return Point(x - a.x, y - a.y);
    }

    T operator*(const Point &a) const {
        return x * a.x + y * a.y;
    }

    T operator^(const Point &a) const {
        return x * a.y - y * a.x;
    }

    int toleft(const Point &a) const {
        T t = (*this) ^ a;
        return (t > 0) - (t < 0);
    }
};

int n, is[N];
Point p[N];

vector<Point> convexhull() {
    const auto check = [&](const vi &res, const Point &u) {
        const auto b1 = p[res.back()], b2 = p[*prev(res.end(), 2)];
        return (b1 - b2).toleft(u - b1) <= 0;
    };
    sort(p, p + n);
    vi res;
    for (int i = 0; i < n; i++) {
        while (res.size() > 1 && check(res, p[i])) res.pop_back();
        res.emplace_back(i);
    }
    int siz = res.size();
    res.pop_back();
    for (int i = n - 1; ~i; i--) {
        while (res.size() > siz && check(res, p[i])) res.pop_back();
        res.emplace_back(i);
    }
    res.pop_back();
    vector<Point> ans;
    for (const auto &it: res) {
        is[it] = 1;
        ans.emplace_back(p[it]);
    }
    return ans;
}

inline void Zlin() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
    if (n <= 2) cout << 0 << endl;
    else {
        ll ans = 0;
        const auto v = convexhull();
        int m = v.size();
        const auto cal = [](const Point &u, const Point &v, const Point &w) { return (u - w) * (v - w); };
        for (int i = 0; i < n; i++) {
            if (!is[i]) {
                for (int j = 0, k = 1; j < m; j++) {
                    while (cal(v[j], v[k], p[i]) > cal(v[j], v[(k + 1) % m], p[i])) k = (k + 1) % m;
                    ans = min(ans, cal(v[j], v[k], p[i]));
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = i + 1, k = j + 1; j < i + m; j++) {
                while (cal(v[j % m], v[k % m], v[i]) > cal(v[j % m], v[(k + 1) % m], v[i])) ++k;
                ans = min(ans, cal(v[j % m], v[k % m], v[i]));
            }
        }
        cout << ans << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
