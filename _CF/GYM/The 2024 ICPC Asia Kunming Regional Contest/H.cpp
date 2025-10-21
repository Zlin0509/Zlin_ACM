//
// Created by 27682 on 2025/10/21.
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

using T = long double;

constexpr T eps = 1e-8;
constexpr T INF = numeric_limits<T>::max();
constexpr T PI = 3.1415926535897932384l;

struct Point {
    T x, y;

    T operator^(const Point &a) const { return x * a.y - y * a.x; }
    T operator*(const Point &a) const { return x * a.x + y * a.y; }

    int quad() const {
        if (abs(x) <= eps && abs(y) <= eps) return 0;
        if (abs(y) <= eps) return x > eps ? 1 : 5;
        if (abs(x) <= eps) return y > eps ? 3 : 7;
        return y > eps ? (x > eps ? 2 : 4) : (x > eps ? 8 : 6);
    }

    T len2() const { return (*this) * (*this); }
    T len() const { return sqrtl(len2()); }
    T ang(const Point &a) const { return acosl(max(-1.0l, min(1.0l, ((*this) * a) / (len() * a.len())))); }
};

struct Argcmp {
    bool operator()(const Point &a, const Point &b) const {
        const int qa = a.quad(), qb = b.quad();
        if (qa != qb) return qa < qb;
        const T t = a ^ b;
        return t > eps;
    }
};

inline void Zlin() {
    int n, k;
    cin >> n >> k;
    vector<Point> v(n);
    for (auto &[x, y]: v) cin >> x >> y;
    sort(v.begin(), v.end(), Argcmp());
    map<Point, int, Argcmp> mp;
    for (const auto &it: v) mp[it]++;
    v.clear();
    for (const auto &it: mp) v.emplace_back(it.first);
    int siz = v.size();
    v.insert(v.end(), v.begin(), v.end());
    T ans = PI * 2;
    for (int i = 0, j = 0, tmp = 0; i < siz; i++) {
        while (j < v.size() && tmp < k) tmp += mp[v[j++]];
        if (tmp >= k) {
            cout << i << ' ' << j << endl;
            ans = min(ans, fabs(v[i].ang(v[j - 1])));
        }
        tmp -= mp[v[i]];
    }
    cout << fixed << setprecision(9) << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
