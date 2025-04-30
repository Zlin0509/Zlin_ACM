//
// Created by Zlin on 2024/11/23.
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

const int N = 2e5 + 10;

ll dif[N];
int a[N], b[N], t[N], d[N];
int n, m, x;

inline void Zlin() {
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= x; i++) cin >> t[i] >> d[i];
    for (int i = 1; i <= n; i++) dif[i] = 1ll * a[i] * m - b[i];
    sort(dif + 1, dif + 1 + n);
    dif[n + 1] = LLONG_MAX;
    for (int i = 1; i <= x; i++) {
        int ans = n + 1;
        ll res = 1ll * t[i] * m + 1ll * d[i] * m * (m - 1) / 2ll;
        for (int j = n; j >= 1; j--) {
            if (dif[i] < res)break;
            ans = min(ans, j);
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}