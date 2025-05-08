//
// Created by Zlin on 2025/5/8.
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

constexpr int N = 5e5 + 10;

int n;
int w[N], c[N], f[N];
int max1[N], c1[N], max2[N], c2[N];
vi fac[N];

inline void Zlin() {
    for (int i = 2; i < N; i++) {
        for (int j = 1; j * i < N; j++) {
            fac[i * j].push_back(i);
        }
    }
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j: fac[w[i]]) {
            if (c1[j] != c[i]) {
                f[i] = max(f[i], max1[j] + 1);
            } else {
                f[i] = max(f[i], max2[j] + 1);
            }
        }
        for (int j: fac[w[i]]) {
            if (c1[j] == c[i] || c2[j] == c[i]) {
                if (c1[j] == c[i]) {
                    max1[j] = max(max1[j], f[i]);
                } else {
                    max2[j] = max(max2[j], f[i]);
                }
                if (max1[j] < max2[j]) {
                    swap(max1[j], max2[j]);
                    swap(c1[j], c2[j]);
                }
            } else {
                if (f[i] >= max1[j]) {
                    max2[j] = max1[j];
                    c2[j] = c1[j];
                    max1[j] = f[i];
                    c1[j] = c[i];
                } else if (f[i] > max2[j]) {
                    max2[j] = f[i];
                    c2[j] = c[i];
                }
            }
        }
        // cout << f[i] << ' ';
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
