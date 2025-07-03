//
// Created by 27682 on 2025/7/3.
//
#include <bits/stdc++.h>
using namespace std;

inline void Zlin() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1, a = '(', b; i <= n << 1; i++, a = b) {
        char c;
        cin >> c;
        b = c;
        if (a == '(' && b == '(') ++ans;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
