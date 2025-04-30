//
// Created by Zlin on 2024/10/7.
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

ll p, a, b, q, c, d, m, t;

inline void Zlin() {
    cin >> p >> a >> b;
    cin >> q >> c >> d;
    cin >> m >> t;
    ll now = m, tt = 0, z, x;
    while (tt < t) {
        x = now / p;
        if (!x) break;
        z = ceil((double) ((x + 1) * p - now) / ((q - p) * x));
        if (tt + z * ((a + c) * x + b + d) > t) {
            z = (t - tt) / ((a + c) * x + b + d);
            if (z == 0) {
                x = (t - tt - b - d) / (a + c);
                if (x > 0)
                    now += x * (q - p);
                break;
            } else {
                now += z * x * (q - p);
                tt += z * ((a + c) * x + b + d);
            }
        } else {
            now += z * x * (q - p);
            tt += z * ((a + c) * x + b + d);
        }
    }
    cout << now << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
}