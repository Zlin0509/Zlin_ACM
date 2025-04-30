//
// Created by Zlin on 2024/10/7.
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

ll s[55][55];

inline void Zlin() {
    int n;
    cin >> n;
    s[1][1] = 1;
    s[1][2] = 2;
    s[2][1] = 3;
    s[2][2] = 4;
    ll p = 5;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            s[j][i] = p;
        }
        p++;
    }
    for (int i = 3; i <= n; i++) {
        s[i][1] = p;
        s[i][2] = p;
        p++;
    }
    cout << "Yes" << "\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << s[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    ttt = 1;
    while (ttt--) Zlin();
}