//
// Created by 27682 on 2025/3/25.
//
#include "bits/stdc++.h"
using namespace std;

inline void Zlin() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    a[n] = INT_MAX;
    sort(a.begin(), a.end());
    for (int i = 1, k; i <= q; i++) {
        cin >> k;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
