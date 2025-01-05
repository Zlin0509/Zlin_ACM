//
// Created by Zlin on 2024/8/28.
//
#include "bits/stdc++.h"

using namespace std;

const int inf = 1e9;

inline void Zlin() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    int cnt = 0;
    vector<int> num(n + 1);
    for (int i = 1; i <= n; i++) {
        if (a[i] != a[i - 1]) ++cnt;
        ++num[cnt - 1];
    }
    n = cnt;
    vector<int> dp(n + 1, inf);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        vector<int> ndp = dp;
        for (int k = 1; k <= n; k++) {
            int nv = dp[k - 1] + num[i - 1];
            if (nv <= i - k) {
                ndp[k] = min(ndp[k], nv);
            }
        }
        dp = ndp;
    }

    int ans = n;
    while (dp[ans] >= inf) ans--;
    cout << n - ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}