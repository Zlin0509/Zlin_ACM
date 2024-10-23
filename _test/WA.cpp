//
// Created by Zlin on 2024/10/23.
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

const int N = 1e5 + 5;
int n, a[N], tt = 1e8;
map<int, int> tzt;
vi used;

inline void dfs(int dep, int cal, int sum) {
    if (dep == used.size()) {
        tt = min(tt, sum);
        return;
    }
    for (auto it: used) {
        if (tzt[it]) continue;
        tzt[it] = 1;
        dfs(dep + 1, gcd(cal, it), sum + gcd(cal, it));
        tzt[it] = 0;
    }
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int tag = a[1];

    used.push_back(a[1]);
    for (int i = 2; i <= n; i++) {
        if (gcd(tag, a[i]) < tag) {
            tag = gcd(tag, a[i]);
            used.push_back(a[i]);
        }
    }
    ll ans = 1ll * tag * (n - used.size());
    for (auto it: used) {
        tzt[it] = 1;
        dfs(1, it, it);
        tzt[it] = 0;
    }
    cout << ans + tt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}