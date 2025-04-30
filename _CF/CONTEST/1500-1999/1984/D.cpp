//
// Created by Zlin on 2024/9/25.
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
    string s;
    cin >> s;
    int n = s.length();
    if (count(s.begin(), s.end(), 'a') == n) {
        cout << n - 1 << '\n';
        return;
    }
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        if (s[i] != 'a') {
            a.push_back(i);
        }
    }
    int m = a.size();
    ll ans = 0;
    for (int i = 1; i <= m; ++i) {
        if (m % i)continue;
        int ok = 1;
        for (int j = i; j < m; ++j) {
            int o = j % i;
            if (s[a[j]] != s[a[o]] || (o && a[o] - a[o - 1] != a[j] - a[j - 1])) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            int mi = n;
            for (int j = i; j < m; j += i) {
                mi = min(mi, a[j] - a[j - 1] - 1);
            }
            int r = n - a.back() - 1;
            for (int l = 0; l <= a[0]; ++l) {
                ans += max(0, min(r + 1, mi - l + 1));
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