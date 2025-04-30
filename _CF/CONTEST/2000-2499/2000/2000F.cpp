//
// Created by Zlin on 2024/9/11.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int inf = 1e6;
int n, k;
pii a[1010];
int dp[610]{}, f[610];


inline void Zlin() {
    for (int j = 1; j <= 520; j++) dp[j] = f[j] = inf;
    cin >> n >> k;
    for (int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        if (x > y)swap(x, y);
        a[i] = {x, y};
    }
    for (int i = 1, m, sum; i <= n; i++) {
        m = a[i].first + a[i].second;
        sum = 0;
        for (int j = 1; j <= m; j++) {
            sum += a[i].first;
            --a[i].second;
            if (a[i].first > a[i].second)swap(a[i].first, a[i].second);
            for (int q = 0; q + j <= k; q++)
                dp[q + j] = min(dp[q + j], f[q] + sum);
        }
        for (int i = 1; i <= k; i++) f[i] = dp[i];
    }
    cout << (f[k] != inf ? f[k] : -1) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}