//
// Created by 27682 on 2025/7/7.
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

constexpr int N = 5e4 + 10;

int n;
ll a[N], b[N];

inline void Zlin() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vll> ans;
    while (1) {
        vll b(n), sum(n);
        for (int i = 0; i < n; i++) b[i] = a[i];
        for (int i = 1; i < n; i++) sum[i] = b[i] + sum[i - 1];
        for (int i = 0; i < n; i++) {
        }
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
