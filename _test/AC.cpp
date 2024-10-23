//
// Created by Zlin on 2024/10/23.
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

const int N = 1e5 + 5;
int n, a[N], dp[30][30], cc[30][30];

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int tag = a[1];
    vi used;
    used.push_back(a[1]);
    for (int i = 2; i <= n; i++) {
        if (gcd(tag, a[i]) < tag) {
            tag = gcd(tag, a[i]);
            used.push_back(a[i]);
        }
    }
    ll ans = 1ll * tag * (n - used.size());
    int len = used.size();
    for (int i = 0; i < len; i++) dp[1][i] = cc[1][i] = used[i];
    for (int i = 2; i <= len; i++) {
        for (int j = 0; j < len; j++) {
            dp[i][j] = 1e8;
            for (int q = 0; q < len; q++) {
                if (dp[i][j] > gcd(cc[i - 1][q], used[j]) + dp[i - 1][q]) {
                    cc[i][j] = gcd(cc[i - 1][q], used[j]);
                    dp[i][j] = cc[i][j] + dp[i - 1][q];
                }
            }
        }
    }
    tag = 1e8;
    for (int i = 0; i < len; i++) tag = min(tag, dp[len][i]);
//    cout << tag << " ";
    cout << ans + tag << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}