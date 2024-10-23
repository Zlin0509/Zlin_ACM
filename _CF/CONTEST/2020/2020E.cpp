//
// Created by Zlin on 2024/10/21.
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

const ll mo = 1e9 + 7;
const int N = 2e5 + 5;

// 快速幂函数：计算 a^b % mo
ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return res;
}

struct ss {
    ll a, b;

    ss operator+(const ss &x) const {
        ss res{a * x.b + b * x.a, b * x.b};
        ll z = gcd(res.a, res.b);
        return {res.a / z, res.b / z};
    }

    ss operator-(const ss &x) const {
        ss res{a * x.b - b * x.a, b * x.b};
        ll z = gcd(res.a, res.b);
        return {res.a / z, res.b / z};
    }

    ss operator*(const ss &x) const {
        ss res{a * x.a, b * x.b};
        ll z = gcd(res.a, res.b);
        return {res.a / z, res.b / z};
    }
} dp[N][1024]{0, 1}, p[N]{0, 1};

int a[N];
int n;

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> p[i].a, p[i].b = 10000;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 1023; j++)
            dp[i][j] = p[i] * dp[i - 1][j ^ a[i]] + (ss{1, 1} - p[i]) * dp[i - 1][j];
    ss res{0, 1};
    for (int i = 1; i <= 1023; i++)
        res = res + dp[n][i] * ss{i * i, 1};
    cout << res.a * qpow(res.b, mo - 2) % mo << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    dp[0][0] = {1, 1};
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}