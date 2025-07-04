//
// Created by 27682 on 2025/7/4.
//
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

inline void Zlin() {
    int n;
    cin >> n;
    vi a(n);
    for (int &it: a) cin >> it;
    int lx = a[0], rx = 0;
    for (int i = 1; i < n; i++) {
        if (rx) {
            if (a[i] - rx < 0) {
                cout << "NO" << endl;
                return;
            }
            if (a[i] - rx > lx) {
                rx = a[i] - lx;
            } else {
                lx = a[i] - rx;
            }
        } else {
            if (a[i] <= lx) lx = a[i];
            else rx = a[i] - lx;
        }
    }
    cout << "YES" << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
