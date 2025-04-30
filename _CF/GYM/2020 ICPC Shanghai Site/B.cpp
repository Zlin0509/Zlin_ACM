//
// Created by Zlin on 2024/10/14.
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

int n, m;
char a[1010][1010], b[1010][1010];

inline void Zlin() {
    cin >> n >> m;
    int c1 = 0, c2 = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'X') ++c1;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> b[i][j];
            if (b[i][j] == 'X') ++c2;
        }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] != b[i][j])
                ++cnt;
    if (cnt > n * m / 2) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                a[i][j] == 'X' ? a[i][j] = '.' : a[i][j] = 'X';
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << a[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
}