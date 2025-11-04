//
// Created by Zlin on 2024/10/11.
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

constexpr int N = 5001;

int lcp[N][N], lcs[N][N], sum[N][N];
string s, t;
int n, m;
ll ans = 0;

inline void Zlin() {
    cin >> s >> t;
    n = s.length(), m = t.length();
    s = ' ' + s, t = ' ' + t;
    for (int i = n; i; i--) {
        for (int j = n; j > i; j--) {
            if (s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
            else lcp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i] == t[j]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else lcs[i][j] = 0;
            sum[i][lcs[i][j]]++;
            ans += lcs[i][j];
        }
        for (int j = n; j; j--) sum[i][j] += sum[i][j + 1];
        for (int j = 1; j <= n; j++) sum[i][j] += sum[i][j - 1];
    }
    for (int l = 1; l <= n; l++) {
        for (int r = l + 2; r <= n; r++) {
            ans += sum[r - 1][r - l - 1] - sum[r - 1][max(r - l - lcp[l][r], 1) - 1];
        }
    }
    swap(s, t);
    swap(n, m);
    memset(lcp, 0, sizeof(lcp));
    memset(lcs, 0, sizeof(lcs));
    memset(sum, 0, sizeof(sum));
    for (int i = n; i; i--) {
        for (int j = n; j > i; j--) {
            if (s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
            else lcp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i] == t[j]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else lcs[i][j] = 0;
            sum[i][lcs[i][j]]++;
        }
        for (int j = n; j; j--) sum[i][j] += sum[i][j + 1];
        for (int j = 1; j <= n; j++) sum[i][j] += sum[i][j - 1];
    }
    for (int l = 1; l <= n; l++) {
        for (int r = l + 2; r <= n; r++) {
            ans += sum[r - 1][r - l - 1] - sum[r - 1][max(r - l - lcp[l][r], 1) - 1];
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
}
