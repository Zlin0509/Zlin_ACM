//
// Created by Zlin on 2025/7/4.
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

constexpr int N = 2e5 + 10;

int n, a[N];
vi v[N], vx[N];

bool is_prime[N];
vi primes;

inline void dd() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < N; i++) {
        if (is_prime[i]) primes.push_back(i);
        for (int j: primes) {
            if (i * j > N) break;
            is_prime[i * j] = false;
            if (i % j == 0) break;
        }
    }
    for (int i: primes) {
        for (int j = 1; i * j < N; j++) {
            v[i * j].push_back(i);
        }
    }
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int tag = a[i];
        for (int v: v[a[i]]) {
            int cnt = 0;
            while (tag % v == 0) {
                ++cnt;
                tag /= v;
            }
            vx[v].emplace_back(cnt);
        }
    }
    ll ans = 1;
    for (int it: primes) {
        sort(vx[it].begin(), vx[it].end());
        if (vx[it].size() == n - 1) {
            int tag = vx[it][0];
            while (tag--) ans *= it;
        } else if (vx[it].size() == n) {
            int tag = vx[it][1];
            while (tag--) ans *= it;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    dd();
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
