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

inline void Zlin() {
    string x;
    int ans = -1;
    cin >> x;
    if (x[0] == x.back()) ans = 0;
    else {
        for (int i = 0; i < x.length() - 1; i++)
            if (x[i] == x[i + 1]) {
                ans = i + 1;
                break;
            }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}