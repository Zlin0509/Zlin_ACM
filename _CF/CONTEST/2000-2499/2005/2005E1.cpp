//
// Created by Zlin on 2024/10/22.
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

const int N = 310;
int t, l, n, m, a[N], b[N][N];
bool f, ans, s[N][N], dp[N][N][N];

inline void Zlin() {
    ans = false;
    cin >> l >> n >> m;
    for (int i = 1; i <= l; i++)cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> b[i][j];
    memset(s, false, sizeof s);
    for (int k = l; k >= 1; k--) {
        for (int i = n; i >= 1; i--) {
            for (int j = m; j >= 1; j--) {
                if (b[i][j] == a[k] && !s[i + 1][j + 1]) {
                    dp[k][i][j] = true;
                } else {
                    dp[k][i][j] = false;
                }
            }
        }
        for (int i = n; i >= 1; i--)
            for (int j = m; j >= 1; j--)
                s[i][j] = s[i + 1][j] | s[i][j + 1] | dp[k][i][j];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans |= dp[1][i][j];
    cout << (ans ? "T" : "N") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}