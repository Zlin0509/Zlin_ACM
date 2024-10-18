//
// Created by Zlin on 2024/10/18.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

struct Point {
    db x, y;
};

Point o1, o2;
db r2;

db dis(int ax, int ay, int bx, int by) {
    return 1ll * (ax - bx) * (ax - bx) + 1ll * (ay - by) * (ay - by);
}

db cal(db x) {
    return sqrt(r2 - (o2.x - x) * (o2.x - x));
}

db check(db mid) {
    return abs(mid - o1.x) + abs(o2.y - o1.y) - cal(mid);
}

inline void Zlin() {
    int ax, ay, bx, by, cx, cy, dx, dy;
    cin >> ax >> ay >> bx >> by;
    cin >> cx >> cy >> dx >> dy;

    o1 = {(ax + bx) / 2.0, (ay + by) / 2.0};
    o2 = {(cx + dx) / 2.0, (cy + dy) / 2.0};
    r2 = (cx == dx && cy == dy) ? 0 : dis(cx, cy, dx, dy) / 4.0;

    if (cx == dx && cy == dy) {
        cout << fixed << setprecision(10) << abs(o2.x - o1.x) + abs(o2.y - o1.y) << '\n';
        return;
    }

    db l = o1.x < o2.x ? o2.x - sqrt(r2) : o2.x;
    db r = o1.x < o2.x ? o2.x : o2.x + sqrt(r2);

    int t = 50;
    while (t--) {
        db mid1 = l + (r - l) / 3.0;
        db mid2 = r - (r - l) / 3.0;
        if (check(mid1) > check(mid2)) l = mid1;
        else r = mid2;
    }
    cout << fixed << setprecision(10) << check(l) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}