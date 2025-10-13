//
// Created by Zlin on 2025/9/10.
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


inline void Zlin() {
    int n, m;
    cin >> n >> m;
    vector<pii> ans;
    auto check = [&](const int &x, const int &y) {
        return 1 <= x && x <= n && 1 <= y && y <= m;
    };
    const int sx = n / 2 + 1, sy = m / 2 + 1;
    ans.emplace_back(sx, sy);
    for (int i = 1, x, y; i <= max(n / 2, m / 2); i++) {
        x = sx - i, y = sy;
        if (check(x, y)) ans.emplace_back(x, y);
        x = sx + i, y = sy;
        if (check(x, y)) ans.emplace_back(x, y);
        for (int j = 1; j < i; j++) {
            x = sx - i, y = sy + j;
            if (check(x, y)) ans.emplace_back(x, y);
            x = sx + i, y = sy + j;
            if (check(x, y)) ans.emplace_back(x, y);
            x = sx - i, y = sy - j;
            if (check(x, y)) ans.emplace_back(x, y);
            x = sx + i, y = sy - j;
            if (check(x, y)) ans.emplace_back(x, y);
        }

        x = sx, y = sy - i;
        if (check(x, y)) ans.emplace_back(x, y);
        x = sx, y = sy + i;
        if (check(x, y)) ans.emplace_back(x, y);
        for (int j = 1; j < i; j++) {
            x = sx + j, y = sy - i;
            if (check(x, y)) ans.emplace_back(x, y);
            x = sx + j, y = sy + i;
            if (check(x, y)) ans.emplace_back(x, y);
            x = sx - j, y = sy - i;
            if (check(x, y)) ans.emplace_back(x, y);
            x = sx - j, y = sy + i;
            if (check(x, y)) ans.emplace_back(x, y);
        }

        x = sx - i, y = sy - i;
        if (check(x, y)) ans.emplace_back(x, y);
        x = sx + i, y = sy + i;
        if (check(x, y)) ans.emplace_back(x, y);
        x = sx - i, y = sy + i;
        if (check(x, y)) ans.emplace_back(x, y);
        x = sx + i, y = sy - i;
        if (check(x, y)) ans.emplace_back(x, y);
    }
    for (const auto &[x, y]: ans)cout << x << ' ' << y << endl;
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
