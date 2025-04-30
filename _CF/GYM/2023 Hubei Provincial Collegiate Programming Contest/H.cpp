//
// Created by 27682 on 2025/2/23.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int N = 998244353;

ll q_pow(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * x % N;
        x = x * x % N;
        n >>= 1;
    }
    return res;
}

inline void Zlin() {
    int n, m;
    cin >> n >> m;
    vll d(n + 1, 0);
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        d[u]++, d[v]++;
    }
    ll cnt00[32][32][32]{0}, cnt11[32][32][32]{0}, cnt10[32][32][32]{0}, cnt01[32][32][32]{0};
    for (int z = 1; z <= n; z++) {
        int tag = d[z];
        for (int c = 0; c < 23; c++) {
            if (!(tag & (1 << c)))
                continue;
            for (int b = 0; b < 23; b++) {
                if (tag & (1 << b)) {
                    for (int a = 0; a < 23; a++) {
                        if (tag & (1 << a))
                            cnt11[a][b][c]++;
                        else
                            cnt01[a][b][c]++;
                    }
                } else {
                    for (int a = 0; a < 23; a++) {
                        if (tag & (1 << a))
                            cnt10[a][b][c]++;
                        else
                            cnt00[a][b][c]++;
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int a = 0; a < 23; a++)
        for (int b = 0; b < 23; b++)
            for (int c = 0; c < 23; c++) {
                ll tag;
                tag = cnt10[a][b][c] * cnt01[a][b][c] % N;
                ans = (ans + tag * (1 << a) % N * (1 << b) % N * (1 << c) % N) % N;
                tag = cnt00[a][b][c] * cnt11[a][b][c] % N;
                ans = (ans + tag * (1 << a) % N * (1 << b) % N * (1 << c) % N) % N;
                tag = cnt11[a][b][c] * cnt00[a][b][c] % N;
                ans = (ans + tag * (1 << a) % N * (1 << b) % N * (1 << c) % N) % N;
                tag = cnt01[a][b][c] * cnt10[a][b][c] % N;
                ans = (ans + tag * (1 << a) % N * (1 << b) % N * (1 << c) % N) % N;
                tag = cnt11[a][b][c] * cnt01[a][b][c] % N;
                ans = (ans + tag * (1 << a) % N * (1 << b) % N * (1 << c) % N) % N;
                tag = cnt01[a][b][c] * cnt11[a][b][c] % N;
                ans = (ans + tag * (1 << a) % N * (1 << b) % N * (1 << c) % N) % N;
            }

    cout << ans * q_pow(2, N - 2) % N << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}