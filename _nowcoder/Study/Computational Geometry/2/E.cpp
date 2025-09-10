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

struct Point {
    db x, y;
};

inline db dis(const Point &a, const Point &b) {
    db dx = a.x - b.x;
    db dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

using Vector = Point;

inline db dot(const Vector &a, const Vector &b) {
    return a.x * b.x + a.y * b.y;
}

inline db cross(const Vector &a, const Vector &b) {
    return a.x * b.y - a.y * b.x;
}

inline Vector operator-(const Point &a, const Point &b) {
    return Vector{a.x - b.x, a.y - b.y};
}

struct Segment {
    Point a, b;
};

struct Line {
    Point p, v;
};

vector<Point> a;
vector<db> l;

constexpr db eps = 1e-3;

inline void Zlin() {
    a.clear(), l.clear();
    for (int i = 0; i < 20; i++) {
        Point tmp;
        cin >> tmp.x >> tmp.y;
        a.emplace_back(tmp);
    }
    for (int i = 0; i < 20; i += 2) l.emplace_back(dis(a[i], a[(i + 1) % 20]));
    sort(l.begin(), l.end());
    db check = 0;
    for (int i = 0; i < 9; i++) check += l[i];
    db mx = 0;
    int lx = 0, rx = 0;
    if (fabs(check - l[9]) <= eps) {
        for (int i = 0; i < 20; i += 2) {
            if (dis(a[i], a[(i + 1) % 20]) > mx) {
                mx = dis(a[i], a[(i + 1) % 20]);
                lx = i, rx = (i + 1) % 20;
            }
        }
    } else {
        for (int i = 1; i < 20; i += 2) {
            if (dis(a[i], a[(i + 1) % 20]) > mx) {
                mx = dis(a[i], a[(i + 1) % 20]);
                lx = i, rx = (i + 1) % 20;
            }
        }
    }
    int op = 0;
    if (dis(a[(lx + 19) % 20], a[lx]) < dis(a[rx], a[(rx + 1) % 20])) op = 1;
    if (cross(a[rx] - a[lx], a[(rx + 1) % 20] - a[lx]) < 0) op ^= 1;
    cout << (op ? "right" : "left") << endl;
}


signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
