//
// Created by Zlin on 2025/4/30.
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

constexpr int N = 2e3 + 10;
constexpr int NN = 2e5 + 10;

ll fac[N];

int f[NN], nxt[NN];

inline void Zlin() {
    for (int i = 1; i < N; i++) fac[i] = 1ll * i * (i - 1) / 2;
    int p;
    cin >> p;
    for (int j = 0; j + 1 <= p; j++) {
        f[j + fac[2]] = f[j] + 2;
        nxt[j + fac[2]] = 2;
    }
    for (int i = 3; i < N; i++) {
        for (int j = 0; j + fac[i] <= p; j++) {
            if (f[j + fac[i]] > f[j] + i) {
                f[j + fac[i]] = f[j] + i;
                nxt[j + fac[i]] = i;
            }
        }
    }
    cout << f[p] << ' ';
    ll sum = 0, ans = 0;
    while (p) {
        ans += sum * nxt[p];
        sum += nxt[p];
        p -= fac[nxt[p]];
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    Zlin();
    return 0;
}
