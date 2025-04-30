//
// Created by Zlin on 2024/9/19.
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
    int l, r;
    cin >> l >> r;
    vi used(r + 1);
    int ans = 0;
    for (int i = l; i < r; i++) {
        if (i % 2 == 0 || used[i]) continue;
        for (int j = i + 1; j <= r; j++) {
            if (j % 2 == 0 || used[j]) continue;
            if (gcd(i, j) == 1) {
                ++used[i], ++used[j], ++ans;
                break;
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