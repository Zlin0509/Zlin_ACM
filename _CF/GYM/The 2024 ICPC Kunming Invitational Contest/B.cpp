//
// Created by Zlin on 2024/10/3.
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
    int n, k, m;
    ll ans = 0;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i] / k;
        a[i] = k - a[i] % k;
    }
    cin >> m;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (m < a[i]) break;
        ++ans;
        m -= a[i];
    }
    ans += m / k;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}