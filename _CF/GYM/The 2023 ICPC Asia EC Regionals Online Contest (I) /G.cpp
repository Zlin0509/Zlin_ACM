//
// Created by Zlin on 2024/10/18.
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

const ll mo = 998244353;

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return res;
}

ll inv(ll a) {
    return qpow(a, mo - 2);
}

const int N = 1e6 + 5;
int n;
int o1[N], o2[N];
map<pii, int> e;
ll x = 1, y = 1;

inline void Zlin() {
    cin >> n;
    for (int i = 1; i < n; i++) cin >> o1[i] >> o2[i];
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[{u, v}] = e[{v, u}] = 1;
    }
    for (int i = 1; i < n; i++) {

    }
    cout << x * inv(y) % mo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}