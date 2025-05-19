//
// Created by Zlin on 2025/5/17.
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

constexpr int N = 2e5 + 10;

int n;
int c[N], w[N];

vector<pii> have[N];

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> w[i];
    int len = 1;
    for (int i = 2; i <= n; i++) {
        if (c[i] != c[i - 1]) {
            have[c[i - 1]].push_back({i - 1, len});
            len = 0;
        }
        ++len;
    }
    have[c[n]].push_back({n, len});
    for (int i = 1, ans; i <= n; i++) {
        ans = w[i] + n;
        for (auto [r, len]: have[i]) {
            int l = r - len + 1;
            if (l == 1 || r == n) {
                ans = min(ans, ans - len);
            } else {
                ans = min(ans, ans + w[i] - len);
            }
        }
        cout << ans << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
