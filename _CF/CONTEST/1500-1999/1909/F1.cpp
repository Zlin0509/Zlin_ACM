//
// Created by 27682 on 2025/4/8.
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

constexpr ll mo = 998244353;

inline void Zlin() {
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (a[n] != n) {
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (a[i + 1] - a[i] > 2 || a[i + 1] - a[i] < 0) {
            cout << 0 << endl;
            return;
        }
    }

    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i - 1] + 1) {
            ans = ans * ((i - a[i - 1]) * 2 - 1) % mo;
        } else if (a[i] == a[i - 1] + 2) {
            ans = ans * (i - a[i - 1] - 1) % mo * (i - a[i - 1] - 1) % mo;
        }
    }
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
