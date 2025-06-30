//
// Created by 27682 on 2025/6/30.
//
#include <bits/stdc++.h>
using namespace std;

inline void Zlin() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '-') {
            vis[i] = 1;
            vis[(i + 1) % n] = 1;
        }
    }
    int tag = true;
    for (int i = 0; i < n; i++) if (s[i] == '<') tag = false;
    if (tag) for (int i = 0; i < n; i++) vis[i] = 1;
    tag = true;
    for (int i = 0; i < n; i++) if (s[i] == '>') tag = false;
    if (tag) for (int i = 0; i < n; i++) vis[i] = 1;
    int ans = 0;
    for (int i = 0; i < n; i++) ans += vis[i];
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
