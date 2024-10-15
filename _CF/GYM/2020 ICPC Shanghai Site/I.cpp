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
    int k;
    db sum[N], ans = 0, all, k2 = 0;
    cin >> n >> m;
    k = ceil(2 * m / pi);
    all = (m * 2 - k * 2 + 1) * 2;
    for (int i = 1; i < k; i++)
        k2 += (db) 2 * i / m;
    cout << k2 << ' ';
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + (i - 1) * m * 2.0 + all * i + k2 * i * pi;
        ans += sum[i];
        cout << sum[i] << ' ';
    }
    cout << ans << ' ';
    ans *= m;
    db cnt = m * (m - 1.0) / 2.0;
    ans += n * (n + 1.0) * m * cnt;
    printf("%.012lf", ans);
}

int main() {
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
}