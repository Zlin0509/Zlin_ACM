//
// Created by 27682 on 2025/5/8.
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
constexpr ll mo = 998244353;

ll fac[N], iv2 = 499122177, iv4 = iv2 * iv2 % mo;

int n, q, x, a[N];

inline ll pw(ll x) {
    if (x == -1) return iv2;
    if (x == -2) return iv4;
    return fac[x];
}

inline ll cal(ll x, ll y) {
    return iv4 * (x * (x + 1) % mo * pw(n - 2) % mo + y * (y + 1) % mo * pw(n - 2) % mo + (
                      mo - x * y % mo * pw(n - 1) % mo) % mo + (mo - pw(n - 1))) % mo;
}

inline void Zlin() {
    cin >> n >> q;
    vll cnt(2);
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        a[i] = c - '0';
        cnt[a[i]]++;
    }
    while (q--) {
        cin >> x;
        cnt[a[x]]--;
        a[x] ^= 1;
        cnt[a[x]]++;
        cout << cal(cnt[0], cnt[1]) << endl;;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * 2 % mo;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
