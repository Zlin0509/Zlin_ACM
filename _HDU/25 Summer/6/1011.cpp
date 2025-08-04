//
// Created by Zlin on 2025/8/4.
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

constexpr int N = 5e5 + 10;

bool is_primes[N];
vi primes;

inline void dd() {
    memset(is_primes, true, sizeof(is_primes));
    is_primes[0] = is_primes[1] = false;
    for (int i = 2; i < N; i++) {
        if (is_primes[i]) primes.emplace_back(i);
        for (int j: primes) {
            if (i * j >= N) break;
            is_primes[i * j] = false;
            if (i % j == 0) break;
        }
    }
}

vi o[N];

int n, m, c, a[N];
int vis[N], cnt[N];

inline void Zlin() {
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) cin >> a[i];
    fill(vis + 1, vis + n + 1, 0);
    for (int i = m; i; i--) {
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    for (int i = 1; i < N; i++)
        for (int j = 1; i * j < N; j++)
            o[i * j].emplace_back(i);
    while (ttt--) Zlin();
    return 0;
}
