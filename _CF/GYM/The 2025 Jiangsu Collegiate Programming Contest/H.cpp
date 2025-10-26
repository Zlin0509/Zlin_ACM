//
// Created by Zlin on 2025/10/25.
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

constexpr int N = 1e6 + 5;
constexpr ll mo = 998244353;

int n, k;
string s;
ll val[N][26];

inline void Zlin() {
    cin >> n >> k >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; i++) for (int j = 0; j < 26; j++) val[i][j] = 0;
    for (int i = n; i; i--) {
        int idx = s[i] - 'a', tx = i + k + 1;
        val[i][idx] = 1;
        if (tx <= n) for (int j = 0; j < 26; j++) val[i][idx] = (val[i][idx] + val[tx][j]) % mo;
        if (i != n) for (int j = 0; j < 26; j++) val[i][j] = max(val[i][j], val[i + 1][j]);
    }
    ll ans = 0;
    for (int j = 0; j < 26; j++) ans = (ans + val[1][j]) % mo;
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
