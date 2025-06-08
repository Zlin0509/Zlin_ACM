//
// Created by 27682 on 2025/6/8.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

inline void Zlin() {
    int n, x;
    cin >> n >> x;
    vi a(n);
    for (int &it: a) cin >> it;
    int lx = n, rx = -1;
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            lx = min(lx, i);
            rx = max(rx, i);
        }
    }
    if (rx == -1 || rx - lx + 1 <= x) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
