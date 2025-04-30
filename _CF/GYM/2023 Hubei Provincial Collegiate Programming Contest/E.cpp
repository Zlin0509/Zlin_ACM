//
// Created by 27682 on 2025/2/23.
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

inline void Zlin() {
    int x;
    cin >> x;
    vector a(31, vll(31, 0));
    vector ans(31, vll(31, 0));
    for (int i = 1; i <= 30; i++)
        a[1][i] = a[i][1] = 1;
    for (int i = 2; i <= 30; i++)
        for (int j = 2; j <= 30; j++)
            a[i][j] = a[i - 1][j] + a[i][j - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}