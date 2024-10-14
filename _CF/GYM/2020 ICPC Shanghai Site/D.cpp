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

//const int NN = 1e6, N = 1e3;

inline void Zlin() {
    ldb n, p1, v1, p2, v2, ans;
    cin >> n >> p1 >> v1 >> p2 >> v2;
    if (p1 > p2) swap(p1, p2), swap(v1, v2);
    ldb t1 = min(n + p1, n + n - p1) / v1, t2 = min(n + p2, n + n - p2) / v2, t3;
    ans = min(t1, t2);
    t3 = max(p2 / v2, (n - p1) / v1);
    ans = min(ans, t3);
    ldb l = p1, r = p2, mid;
    int t = 110;
    while (t--) {
        mid = (l + r) / 2;
        t1 = min((p1 + mid) / v1, (mid + mid - p1) / v1);
        t2 = min((n - p2 + n - mid) / v2, (p2 + n - mid - mid) / v2);
        ans = min(ans, max(t1, t2));
        if (t1 > t2) r = mid;
        else l = mid;
    }
    printf("%.012lf\n", (db) ans);
}

int main() {
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
}