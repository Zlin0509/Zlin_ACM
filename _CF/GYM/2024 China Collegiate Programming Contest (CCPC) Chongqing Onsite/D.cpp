//
// Created by 27682 on 2025/10/13.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 1e6;
constexpr int INF = 1e9;

ll fac2[40], fac5[30];

inline void init() {
    fac2[0] = fac5[0] = 1;
    for (int i = 1; i < 40; i++) fac2[i] = fac2[i - 1] * 2;
    for (int i = 1; i < 30; i++) fac5[i] = fac5[i - 1] * 5;
}

// 扩展欧几里得算法，返回 gcd(a, b)，并且计算出 x 和 y
// 使得 ax + by = gcd(a, b)
inline ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    ll x1, y1, gcd = exgcd(b, a % b, x1, y1);
    x = y1, y = x1 - a / b * y1;
    return gcd;
}

inline void Zlin() {
    int a, b;
    cin >> a >> b;
    int b2 = 0, b5 = 0, bs;
    for (int i = 0; fac2[i] <= N; i++) {
        for (int j = 0; fac2[i] * fac5[j] <= N; j++) {
            if (b % (fac2[i] * fac5[j]) == 0) {
                b2 = i, b5 = j;
                bs = b / fac2[i] / fac5[j];
            }
        }
    }
    int c = INF, d = INF;
    for (int i = 0; fac2[i] <= INF; i++) {
        for (int j = 0; fac2[i] * fac5[j] <= INF; j++) {
            ll ea = bs, eb = -bs, ec = -1;
            if (i > b2) ec = ec * fac2[i - b2];
            if (i < b2) ea = ea * fac2[b2 - i];
            if (i > b5) ec = ec * fac5[i - b5];
            if (i < b5) ea = ea * fac5[b5 - i];
            ll x, y, g = exgcd(ea, eb, x, y);
            if (ec % g) continue;
            x *= ec / g, y *= ec / g;
            ll step = eb / g;
            ll k;
            if (step > 0) k = (1 - x + step - 1) / step;
            else k = (1 - x) / step;
            x += k * step;
            y -= k * (ea / g);
            if (c > x) x = c, d = fac2[i] * fac5[j];
            cout << ea << ' ' << eb << ' ' << ec << ' ' << g << endl;
        }
    }
    cout << c << ' ' << d << endl;
}

/*

4
1 2
2 3
3 7
19 79

*/

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    init();
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
