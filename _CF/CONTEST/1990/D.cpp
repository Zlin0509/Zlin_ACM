//
// Created by Zlin on 2024/8/17.
//
#include "bits/stdc++.h"

using namespace std;

inline void Zlin() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 2), c(n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= 5) ++ans;
        else if (a[i]) {
            if (a[i] >= 3) {
                if (!b[i] && !c[i]) ++ans;
                else if (!b[i]) ++ans, b[i + 1] = b[i] = 1;
                else if (!c[i]) ++ans, c[i + 1] = c[i] = 1;
            }
            if (a[i] <= 2 && !b[i]) {
                ++ans;
                b[i + 1] = b[i] = 1;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}