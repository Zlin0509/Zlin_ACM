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

const int N = 1e3;

inline void Zlin() {
    ldb n, p1, v1, p2, v2, ans;
    cin >> n >> p1 >> v1 >> p2 >> v2;
    n *= N, p1 *= N, p2 *= N;
    if (p1 > p2) swap(p1, p2), swap(v1, v2);
    ldb t1, t2, t3;
    t1 = min(n + p1, n * 2 - p1) / v1;
    t2 = min(n + p2, n * 2 - p2) / v2;
    ans = min(t1, t2);

    t1 = (n - p1) / v1;
    t2 = p2 / v2;
    ans = min(ans, max(t1, t2));

    t3 = (2 * v1 * n - v1 * p2 - v2 * p1) / (v1 + v2);
    if (t3 >= p1 && t3 <= p2) {
        t1 = (p1 + t3) / v1;
        t2 = (n * 2 - p2 - t3) / v2;
        ans = min(ans, max(t1, t2));
    }

    t3 = (v1 * (n - p2) + v2 * p1) / (2 * v1 + 2 * v2);
    if (t3 >= p1 && t3 <= p2) {
        t1 = (n - 2 * t3 + p2) / v2;
        t2 = (2 * t3 - p1) / v1;
        ans = min(ans, max(t1, t2));
    }

    ans /= N;
    printf("%.012lf\n", (db) ans);
}

int main() {
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
}