//
// Created by Zlin on 2025/10/25.
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

constexpr int N = 1e6 + 5;

int val[N], a[N], cnt[N];
int n, q, m;

inline void Zlin() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int l = a[i], r = a[i + 1];
        for (int j = l; j < r; j++) {
            val[j] = j / a[i] + val[j % a[i]];
        }
    }
    for (int i = 1; i < a[n]; i++) cnt[val[i]]++;
    for (int i = 2; i < a[n]; i++) cnt[i] += cnt[i - 1];
    while (q--) {
        cin >> m;
        cout << cnt[min(m, a[n] - 1)] + 1 << ' ';
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
