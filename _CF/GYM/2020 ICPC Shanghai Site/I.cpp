//
// Created by Zlin on 2024/10/14.
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

const db pi = 3.14159265358979323846;

const int N = 510;

inline void Zlin() {
    int n, m;
    db ans = 0.0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        db r = i, tmp = pi * r / m;
        db res = 0.0;
        if (m > 1) ans += r * m * 2;
        for (int j = 1; j < m * 2; j++) {
            db k = min(j, m * 2 - j);
            res += min(k * tmp, 2.0 * r);
        }
        res *= m;
        ans += res * (1 + 2 * (n - i));
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            ans += (j - i) * (2 * m * 2 * m);
    cout << fixed << setprecision(10) << ans << '\n';
}

int main() {
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
}