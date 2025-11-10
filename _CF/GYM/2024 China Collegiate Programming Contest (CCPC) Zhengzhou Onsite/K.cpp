//
// Created by Zlin on 2025/11/10.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
constexpr int N = 1e5 + 10;
constexpr ldb eps = 1e-15;
int n, k;
ldb p, Exp[N];

inline void Zlin() {
    cin >> n >> k >> p;
    for (int i = 2; i <= n; i++) {
        ldb tmp = p, val = Exp[i - 1] + 1, Nexp = 1 - p;
        int dep = 1;
        while (tmp + eps < 1) {
            tmp += Nexp * p;
            val += Nexp * p * (dep + 1) * (Exp[i - 1] + 1);
            // cout << fixed << setprecision(9) << tmp << " " << val << endl;
            dep += 1, Nexp *= 1 - p;
        }
        Exp[i] = val;
    }
    for (int i = 1; i <= n; i++) cout << Exp[i] << " ";
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
