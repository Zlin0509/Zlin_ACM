//
// Created by Zlin on 2024/9/20.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

inline void Zlin() {
    int a, b, c, ans = 0;
    cin >> a >> b >> c;
    for (int i = 0; i <= 5; i++) {
        for (int j = 0; i + j <= 5; j++) {
            for (int q = 0; i + j + q <= 5; q++) {
                ans = max(ans, (a + i) * (b + j) * (c + q));
            }
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