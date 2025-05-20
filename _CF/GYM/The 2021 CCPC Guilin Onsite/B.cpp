//
// Created by Zlin on 2025/4/13.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

inline void Zlin() {
    int n, q;
    cin >> n >> q;
    vi a(n + 1), b(n + 1);
    set<int> sl;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        a[i] = c - '0';
    }
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        b[i] = c - '0';
    }
    for (int i = n; i; i--) {
        if (a[i] + b[i] != 9) {
            sl.insert(i);
        }
    }

    auto upd = [&](int x, int y, int r, int c, int d) {
        if (x % 10 != 9 && y % 10 == 9)
            sl.erase(c);
        if (x % 10 == 9 && y % 10 != 9)
            sl.insert(c);
        r == 1 ? a[c] = d : b[c] = d;
    };

    auto cal_suf = [&](int x) {
        auto it = sl.upper_bound(x);
        if (it == sl.end()) return 0;
        return (a[*it] + b[*it]) / 10;
    };

    auto cal_pre = [&](int x) {
        auto it = sl.lower_bound(x);
        if (it == sl.begin()) return x - 1;
        return x - *(--it);
    };

    while (q--) {
        int r, c, d;
        cin >> r >> c >> d;
        int x = a[c] + b[c];
        int y = r == 1 ? d + b[c] : d + a[c];
        int now = cal_suf(c);
        if (x == y) {
            cout << (y + now) % 10 << ' ' << 0 << endl;
        } else if ((x + now) / 10 == (y + now) / 10) {
            cout << (y + now) % 10 << ' ' << 2 << endl;
            upd(x, y, r, c, d);
        } else {
            cout << (y + now) % 10 << ' ' << cal_pre(c) + 2 << endl;
            upd(x, y, r, c, d);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    // cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
