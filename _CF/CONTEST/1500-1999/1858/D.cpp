//
// Created by 27682 on 2025/4/14.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 3010;
int f[2][N][N], sum[N];

inline void Zlin() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            f[0][i][j] = f[1][i][j] = 0;
        }
    }
    string s;
    cin >> s;
    s = ' ' + s;
    for (int i = 1, l0 = -1, l1 = -1; i <= n; i++) {
        if (s[i] == '0') {
            f[0][i][i] = 1;
            l0 = i;
        }
        if (s[i] == '1') {
            f[1][i][i] = 1;
            l1 = i;
        }
        for (int j = i + 1; j <= n; j++) {
            f[0][i][j] = f[0][i][j - 1];
            f[1][i][j] = f[1][i][j - 1];
            if (s[j] == '0') {
                if (l0 == -1) l0 = j;
                f[0][i][j] = max(f[0][i][j], j - l0 + 1);
                l1 = -1;
            }
            if (s[j] == '1') {
                if (l1 == -1) l1 = j;
                f[1][i][j] = max(f[1][i][j], j - l1 + 1);
                l0 = -1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + (s[i] == '1');
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
