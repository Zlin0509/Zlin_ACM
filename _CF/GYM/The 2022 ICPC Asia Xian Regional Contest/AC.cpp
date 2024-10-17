//
// Created by Zlin on 2024/10/17.
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

const ll N = 1e7;
vll a(N + 10);

void dd() {
    a[0] = 1;
    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0) a[i] = a[i / 3] + 1;
        else a[i] = a[i - 1] + 1;
    }
}

inline void Zlin() {
    ll l, r;
    cin >> l >> r;
    ll ans = 0;
    for (ll i = l; i < r; i++) {
//        cout << a[i] << ' ' << i << '\n';
        ans = max(ans, a[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    dd();
    while (ttt--) Zlin();
    return 0;
}