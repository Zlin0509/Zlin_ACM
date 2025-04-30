//
// Created by Zlin on 2025/4/28.
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

constexpr int N = 1005;

int n, m;
int a[N][N], cntx[N], cnty[N], tagx[N];

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    for (int i = 1; i <= n; i++) cntx[i] = 0;
    for (int i = 1; i <= m; i++) cnty[i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] + cnty[j] & 1) {
                cntx[i] ^= 1, cnty[j] ^= 1;
            }
        }
        if (cntx[i]) {
            cntx[i] ^= 1;
            if (i != n) {
                for (int j = 1; j <= n; j++) {
                    a[i + 1][j] ^= 1;
                }
            } else {
                for (int j = 1; j <= n; j++) {
                    a[i][j] ^= 1;
                }
            }
        }
    }
    int cnt = 0;
    for (int j = 1; j <= m; j++) {
        if (cnty[j]) {
            if (a[n][j]) {
                cout << "NO" << endl;
                return;
            }
            ++cnt;
        }
    }
    cout << (cnt & 1 ? "NO" : "YES") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
