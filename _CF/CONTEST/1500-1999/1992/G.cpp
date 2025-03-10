//
// Created by Zlin on 2024/9/13.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const ll mo = 1e9 + 7;

ll c[5010][5010];

inline void prework() {
    for (int i = 0; i <= 5001; i++)
        for (int j = 0; j <= i; j++)
            if (!j)
                c[i][j] = 1;
            else
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    prework();
    int ttt;
    cin >> ttt;
    while (ttt--) {
        ll ans = 1;
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            if (i * 2 >= n) ans = (ans + c[n][i] * (i * 2 + 1)) % mo;
            else {
                for (int k = i + 1; k <= i * 2 + 1; k++) {
                    ans = (ans + c[k - 1][k - 1 - i] * c[n - k][2 * i - k + 1] % mo * k % mo) % mo;
                }
            }
        }

        cout << ans << '\n';
    }
}