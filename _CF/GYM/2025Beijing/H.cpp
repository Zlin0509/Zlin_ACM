//
// Created by Zlin on 2025/5/8.
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

int n, m, p, k = 1, idx[1005], tag[1005];
bitset<1005> a[1005], b[1005], c[1005];

inline void gauss() {
    for (int i = 1000; i && k <= n; i--) {
        for (int j = k; j <= n; j++)
            if (a[j][i]) {
                swap(a[j], a[k]);
                swap(c[j], c[k]);
                break;
            }
        if (!a[k][i]) continue;
        idx[i] = k;
        for (int j = 1; j <= n; j++) {
            if (j != k && a[j][i]) {
                a[j] ^= a[k];
                c[j] ^= c[k];
            }
        }
        ++k;
    }
    for (int i = 1; i <= 1000; i++) {
        bool check = false;
        for (int j = 1; j <= 1000; j++) {
            if (a[i][j]) {
                check = true;
                break;
            }
        }
        tag[i] = check;
    }
}

inline void Zlin() {
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            bool x;
            cin >> x;
            a[i][j] = x;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= p; j++) {
            bool x;
            cin >> x;
            c[i][j] = x;
        }
    }
    gauss();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= p; j++) {
            if (!tag[i] && c[i][j]) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    for (int j = 1; j <= p; j++) {
        for (int i = 1; i <= m; i++) {
            if (idx[i]) {
                b[i][j] = c[idx[i]][j];
            } else {
                b[i][j] = false;
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= p; j++) {
            cout << b[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
