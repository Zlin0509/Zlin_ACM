//
// Created by Zlin on 2024/9/20.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

inline void Zlin() {
    int n, k, mx = 0;
    cin >> n >> k;
    vi a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    ll ans = k - 1 + (n - mx - k + 1) * 2ll;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}