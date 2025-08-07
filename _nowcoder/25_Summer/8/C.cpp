//
// Created by Zlin on 2025/8/7.
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

constexpr int N = 1e5 + 10;

int n, H;
int a[N], idx[N];
db b[N];

inline void Zlin() {
    cin >> n >> H;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        idx[i] = i;
        b[i] = 2 * sqrt(1ll * a[i] * (H - a[i]));
    }
    sort(idx + 1, idx + 1 + n, [&](int i, int j) { return b[i] < b[j]; });
    for (int i = 1; i <= n; i++) cout << idx[i] << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
