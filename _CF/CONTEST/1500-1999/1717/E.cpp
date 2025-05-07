//
// Created by 27682 on 2025/5/6.
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

constexpr int N = 1e5 + 10;
constexpr ll mo = 1e9 + 7;

int fac[N];

int phi(int n) {
    int res = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res -= res / i;
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) res -= res / n;
    return res;
}

inline void Zlin() {
    for (int i = 2; i < N; i++) fac[i] = phi(i);
    int n;
    cin >> n;
    ll ans = 0;
    for (int l = 1, r; l < n; l++) {
        for (int k = 2, val; l * k < n; k++) {
            r = n - l * k;
            val = 1ll * l * r / gcd(l, r) % mo * fac[k] % mo;
            ans = (ans + val) % mo;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
