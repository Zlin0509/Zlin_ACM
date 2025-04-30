//
// Created by Zlin on 2025/4/28.
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

constexpr db inf = 1e18;

struct node {
    db x, w, c;

    bool operator<(const node &a) const {
        return x < a.x;
    }
};

inline void Zlin() {
    int n, k;
    cin >> n >> k;
    vector<node> a(n);
    for (auto &[x, w, c]: a) {
        cin >> x >> w >> c;
        x *= 0.01;
    }
    sort(a.begin(), a.end());
    vector f(n, 0.0);
    db ans = 0.0;
    for (int i = 0; i < n; i++) {
        db res = 0.0;
        for (int j = 0; j < i; j++) res = max(res, f[j] + (a[i].c + a[j].c) * (a[i].x - a[j].x) / 2.0 * k);
        f[i] = res - a[i].w;
        ans = max(ans, f[i]);
    }
    cout << fixed << setprecision(12) << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
