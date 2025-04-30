//
// Created by 27682 on 2025/3/30.
//
#include "bits/stdc++.h"
using namespace std;

inline void Zlin() {
    int n, m;
    cin >> n >> m;
    vector a(n + 1, vector<int>(m + 1));
    if (m & 1) {
        for (int i = 1; i <= n; i++) {
            if (i & 1) {
                for (int j = 1; j <= m; j++) {
                    a[i][j] = (i - 1) * m + j;
                }
            } else {
                a[i][1] = i * m;
                for (int j = 1; j < m; j++) {
                    a[i][j + 1] = (i - 1) * m + j;
                }
            }
        }
    } else {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                a[i][j] = (i - 1) * m + j;
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
}
