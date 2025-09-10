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
    int x, y;
};

using Vector = Point;

struct Segment {
    Point a, b;
};

struct Line {
    Point p, v;
};

struct Polygon {
    vector<Point> p;
};

inline void Zlin() {
    cout << 0 << ' ' << 0 << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
