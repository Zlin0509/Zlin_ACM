//
// Created by 27682 on 2025/3/13.
//
#include "bits/stdc++.h"

using namespace std;

inline void Zlin() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &it: a)
        cin >> it;
    sort(a.begin(), a.end());
    int ans = INT_MAX;
    for (int i = 0; i + k - 1 < n; i++) {
        ans = min(ans, a[i + k - 1] - a[i]);
    }
    cout << ans << endl;
}

int main() {
    int ttt = 1;
    while (ttt--)
        Zlin();
    return 0;
}