//
// Created by 27682 on 2025/11/11.
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

constexpr int W = 1e5;

int l;

int base;

inline int cal(int i) {
    int cnt = base / i;
    return ceil(1.0 * W / cnt);
}

inline void Zlin() {
    // cout << "? ";
    // for (int i = 1; i <= W; i++) cout << 2 << " "[i == W];
    // cout << endl;
    // cin >> l;
    l = cal(2);
    if (l == 0) {
        cout << "! " << 1 << endl;
        return;
    }
    vi ans;
    for (int i = 1; i <= W; i++) {
        int check = i / 2 * (l - 1);
        if (check + 1 <= W && W <= check + i / 2) ans.emplace_back(i);
    }
    // cout << "? ";
    // for (int i = 1; i <= W; i++) cout << 3 << " "[i == W];
    // cout << endl;
    // cin >> l;
    l = cal(3);
    if (l == 0) {
        cout << "! " << 2 << endl;
        return;
    }
    for (const int &it: ans) {
        int check = it / 3 * (l - 1);
        if (check + 1 <= W && W <= check + it / 3) cout << "! " << it << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    // cin >> ttt;
    // while (ttt--) Zlin();
    for (int i = 3; i <= 10; i++) {
        base = i;
        Zlin();
        cout << endl;
    }
    return 0;
}
