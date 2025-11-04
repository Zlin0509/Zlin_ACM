//
// Created by 27682 on 2025/11/4.
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

constexpr int N = 1e7 + 5;

vi primes;
bool is_p[N];

inline void prework() {
    fill(is_p, is_p + N, true);
    is_p[0] = is_p[1] = false;
    for (int i = 2; i < N; i++) {
        if (is_p[i]) primes.emplace_back(i);
        for (int j: primes) {
            if (i * j > N) break;
            is_p[i * j] = false;
            if (i % j == 0) break;
        }
    }
}

inline void work() {
    int mx = 0;
    for (int i = 1; i < primes.size(); i++) mx = max(mx, primes[i] - primes[i - 1]);
    mx = max(mx, N - primes.back());
    cout << mx;
}

inline void Zlin() {
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    prework();
    work();
    // cin >> ttt;
    // while (ttt--) Zlin();
    return 0;
}
