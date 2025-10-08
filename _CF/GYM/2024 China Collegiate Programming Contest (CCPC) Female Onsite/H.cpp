//
// Created by Zlin on 2025/10/8.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline void Zlin() {
    string s;
    cin >> s;
    int n = s.length();
    int len = 0;
    db ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ++len;
        } else {
            if (len) {
                if (len & 1) {
                    ans += (int) (len + 1) / 2;
                } else {
                    ans += (int) (len - 1) / 2;
                    ans += sqrt(2);
                }
                len = 0;
            }
        }
    }
    if (len) {
        if (len & 1) {
            ans += (int) (len + 1) / 2;
        } else {
            ans += (int) (len - 1) / 2;
            ans += sqrt(2);
        }
    }
    cout << fixed << setprecision(12) << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
