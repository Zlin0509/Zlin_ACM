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

inline void Zlin() {
    int n, t, ans = 0;
    cin >> n >> t;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans = max(ans, a[i]);
    }
    ans = ceil((db) ans / t);
    cout << max(2, ans) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}