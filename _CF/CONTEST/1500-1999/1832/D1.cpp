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
        vector<int> b = a;
        if (k <= n) {
            for (int j = 0; j < k; j++)
                b[j] += k - j;
            sort(b.begin(), b.end());
            cout << b[0] << ' ';
            continue;
        }
        for (int j = 0; j < n - 1; j++) b[j] += k - j;
        if ((n + k) % 2 == 0) b[n - 1] += k - n + 1;
        sort(b.begin(), b.end());
        long long sum = 0;
        for (int j = 1; j < n; j++) sum += b[j] - b[0];
        double f = max(0.0, (k - (n - (n + k) % 2)) / 2.0 - sum);
        int ans = ceil(f / n);
        cout << b[0] - ans << ' ';
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
