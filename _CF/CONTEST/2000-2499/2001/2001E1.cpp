//
// Created by Zlin on 2024/10/2.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, K;
ll P;
ll f[5010][5010], g[5010][5010];
ll Sg[5010];

inline void Zlin() {
    cin >> n >> K >> P;
    Sg[0] = 0ll;
    for (int i = 0; i <= K; i++) {
        f[1][i] = g[1][i] = 1ll;
        Sg[i + 1] = (Sg[i] + g[1][i]) % P;
    }
    for (int i = 2; i <= n; i++) {
        auto Sumg = [&](int l, int r) {
            return l > r ? 0ll : (Sg[r + 1] - Sg[l]) % P;
        };
        for (int j = 0; j <= K; j++) {
            f[i][j] = g[i][j] = 0ll;
            for (int x = 0; x <= j; x++) {
                f[i][j] = (f[i][j] + 2ll * f[i - 1][x] * Sumg(0, min(x - 1, j - x)) % P) % P;
                g[i][j] = (g[i][j] + 1ll * g[i - 1][x] * Sumg(0, j - x) % P) % P;
            }
        }
        Sg[0] = 0ll;
        for (int j = 0; j <= K; j++) Sg[j + 1] = (Sg[j] + g[i][j]) % P;
    }
    cout << f[n][K] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}