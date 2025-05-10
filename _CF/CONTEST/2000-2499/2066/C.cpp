//
// Created by 27682 on 2025/5/9.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int N = 2e5 + 10;
constexpr ll mo = 1e9 + 7;

int n, a[N];
map<int, ll> val;

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    val.clear();
    val[0] = 1;
    for (int i = 1; i <= n; i++) {
        a[i] ^= a[i - 1];
        val[a[i - 1]] = (3 * val[a[i - 1]] + 2 * val[a[i]]) % mo;
    }
    ll ans = 0;
    for (auto it: val) {
        ans = (ans + it.second) % mo;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
