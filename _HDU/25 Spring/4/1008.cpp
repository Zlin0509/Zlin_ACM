//
// Created by 27682 on 2025/3/28.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline void Zlin() {
    int n, k;
    cin >> n >> k;
    vector a(n, vll(k));
    vector f(n, vll(k));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
        }
    }
    f[n - 1][k - 1] = a[n - 1][k - 1];
    for (int j = k - 2; ~j; j--)
        f[n - 1][j] = max(f[n - 1][j + 1], a[n - 1][j]);
    for (int i = n - 2; ~i; i--) {
        f[i][k - 1] = a[i][k - 1] + f[i + 1][k - 1];
        for (int j = k - 2; ~j; j--)
            f[i][j] = max(f[i][j + 1], a[i][j] + f[i + 1][j]);
    }
    ll ans = 0;
    for (int i = 0; i < k; i++)
        ans = max(ans, f[0][i]);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
