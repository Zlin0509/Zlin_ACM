//
// Created by 27682 on 2025/5/7.
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

constexpr int N = 4e5 + 10;

int n, a[N], b[N], val[N];
ll k, sa[N], sb[N];

inline void Zlin() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        b[i + n] = b[i];
    }
    for (int i = 1; i <= n << 1; i++) {
        sa[i] = sa[i - 1] + a[i];
        sb[i] = sb[i - 1] + b[i];
    }
    int ans = 0;
    for (int i = 1, rx; i <= n; i++) {
        rx = max(i, val[i - 1]);
        while (sa[rx] - sa[i - 1] > sb[rx] - sb[i - 1]) ++rx;
        val[i] = rx;
        ans = max(ans, rx - i + 1);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}