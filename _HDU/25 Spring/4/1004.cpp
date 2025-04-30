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

constexpr int N = 1e5 + 10;

int n, a[N], f[N];
vi e[N];

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        f[i] = 0;
        e[i].clear();
    }
    for (int i = 2, fa; i <= n; i++) {
        cin >> fa;
        e[fa].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
