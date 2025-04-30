//
// Created by Zlin on 2025/4/16.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr ll mo = 998244353;
constexpr int N = 5e5;

ll fac1[N + 10], fac2[N + 10];


inline ll dfs(vi now) {
    if (now.size() == 1) return 1;
    int n = now.size();
    int x = 0, y = n / 2;
    for (int it: now) y -= it > n / 2;
    vi suf;
    for (int i = 0, l, r; i < n / 2; i++) {
        l = i * 2, r = i * 2 + 1;
        if (now[l] != -1 && now[r] != -1) {
            if (now[l] <= n / 2 == now[r] <= n / 2) {
                return 0;
            }
        }
        if (now[l] == -1 && now[r] == -1) ++x;
        if (now[l] != -1 && now[l] <= n / 2) {
            suf.push_back(now[l]);
        } else if (now[r] != -1 && now[r] <= n / 2) {
            suf.push_back(now[r]);
        } else {
            suf.push_back(-1);
        }
    }
    return fac1[x] * fac2[y] % mo * dfs(suf) % mo;
}

inline void Zlin() {
    int n, k;
    cin >> k;
    n = 1 << k;
    vi a(n);
    for (int &it: a) cin >> it;
    cout << dfs(a) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    fac1[0] = fac2[0] = 1;
    for (int i = 1; i <= N; i++) {
        fac1[i] = fac1[i - 1] * 2 % mo;
        fac2[i] = fac2[i - 1] * i % mo;
    }
    // cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
