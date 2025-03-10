//
// Created by Zlin on 2024/9/4.
//

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;

unordered_map<int, int> used;

ll gcd(ll a, ll b) {
    ll az = __builtin_ctzll(a), bz = __builtin_ctzll(b); // 如果数据ll，用函数ctzll
    ll z = min(az, bz), dif;
    b >>= bz;
    while (a) {
        a >>= az;
        dif = llabs(b - a);
        az = __builtin_ctzll(dif);
        if (a < b)
            b = a;
        a = dif;
    }
    return b << z;
}

inline ll lcm(ll x, ll y) {
    return x * y / gcd(x, y);
}

inline void Zlin() {
    used.clear();
    int n;
    cin >> n;
    vll a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i], ++used[a[i]];
    sort(a.begin() + 1, a.end());
    ll z = 1;
    for (int i = 1; i <= n; i++) {
        if (z != a[i])
            z = lcm(z, a[i]);
        if (z > a.back()) {
            cout << n << '\n';
            return;
        }
    }
    vi zz;
    for (int i = 2; i <= sqrt(a.back()); i++) {
        if (a.back() % i == 0) {
            zz.push_back(i);
            if (a.back() / i != i) zz.push_back(a.back() / i);
        }
    }
    int ans = 0;
    for (auto it: zz) {
        int cnt = 0;
        z = 1;
        for (int i = 1; i <= n; i++)
            if (it % a[i] == 0) ++cnt, z = lcm(z, a[i]);
        bool check = true;
        for (int i = 1; i <= n; i++)
            if (a[i] == z) {
                check = false;
                break;
            }
        if (check)
            ans = max(ans, cnt);
    }
    if (ans == 1) ans = 0;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}