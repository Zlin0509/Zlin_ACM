//
// Created by Zlin on 2024/9/4.
//

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

inline void Zlin() {
    ll n, b, x, mx = 0, ans = 0;
    cin >> n >> b >> x;
    vll c(n + 1);
    for (int i = 1; i <= n; i++) cin >> c[i], mx = max(mx, c[i]);
    auto cal = [&](ll x, ll k) {
        ll a = x / k, b = x / k + 1;
        ll c = k - x % k, d = x % k;
        if (x == k) return x * (x - 1) / 2;
        if (!d) return k * (k - 1) * a * a / 2;
        return a * b * c * d + a * a * c * (c - 1) / 2 + b * b * d * (d - 1) / 2;
    };
    vll sum(mx + 1), add(mx + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j < c[i]; j++)sum[j] += cal(c[i], j);
        add[c[i]] += cal(c[i], c[i]);
    }
    ll other = 0;
    for (int j = 1; j <= mx; j++) {
        other += add[j];
        ans = max(ans, b * (sum[j] + other) - x * (j - 1));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}