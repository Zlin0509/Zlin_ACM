//
// Created by Zlin on 2025/5/24.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int x, y, r, vx, vy;
int lx, rx, ly, ry;

inline db cal(db s, db t, db k) {
    return (t - s) / k;
}


inline void Zlin() {
    cin >> x >> y >> r >> vx >> vy;
    if (vx && vy) {
        int z = gcd(vx, vy);
        vx /= z, vy /= z;
    }
    cin >> lx >> ly >> rx >> ry;
    pair<db, db> px = {lx + r, rx - r}, py = {ly + r, ry - r};
    if (vx) {
        if (px.first <= x && px.second >= x) {
            if (vx > 0) px = {cal(x, x, vx), cal(x, px.second, vx)};
            if (vx < 0) px = {cal(x, x, vx), cal(x, px.first, vx)};
        } else if (px.first > x) {
            if (vx > 0) px = {cal(x, px.first, vx), cal(x, px.second, vx)};
            if (vx < 0) px = {1, -1};
        } else {
            if (vx > 0) px = {1, -1};
            if (vx < 0) px = {cal(x, px.second, vx), cal(x, px.first, vx)};
        }
    } else {
        px = {1, -1};
        if (x >= lx + r && x <= rx - r) px = {-1e9, 1e9};
    }
    if (vy) {
        if (py.first <= y && py.second >= y) {
            if (vy > 0) py = {cal(y, y, vy), cal(y, py.second, vy)};
            if (vy < 0) py = {cal(y, y, vy), cal(y, py.first, vy)};
        } else if (py.first > y) {
            if (vy > 0) py = {cal(y, py.first, vy), cal(y, py.second, vy)};
            if (vy < 0) py = {1, -1};
        } else {
            if (vy > 0) py = {1, -1};
            if (vy < 0) py = {cal(y, py.second, vy), cal(y, py.first, vy)};
        }
    } else {
        py = {1, -1};
        if (y >= ly + r && y <= ry - r) py = {-1e9, 1e9};
    }
    pair<db, db> p;
    p.first = max(px.first, py.first);
    p.second = min(px.second, py.second);
    if (p.first > p.second || p.second < 0) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
