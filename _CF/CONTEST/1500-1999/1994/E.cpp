//
// Created by Zlin on 2024/9/13.
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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 1, x; j < a[i]; j++) cin >> x;
    }
    sort(a.begin(), a.end(), greater<int>());
    int ans = 0;
    for (auto it: a) {
        for (int i = 31; ~i; i--) {
            int x = (1 << i) & ans;
            int y = (1 << i) & it;
            if (!y) continue;
            x ? ans |= (1 << i) - 1 : ans |= (1 << i);
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