//
// Created by 27682 on 2025/7/22.
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

int n, a;
string s;

inline void Zlin() {
    cin >> n >> a >> s;
    int ans = 0, len1 = 0, len0 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            len1 = 0;
            ++len0;
        }
        if (s[i] == '1') {
            len0 = 0;
            ++len1;
        }
        if (len0 == a + 1 || len1 == a) {
            ans = n;
            break;
        }
    }
    if (!ans) for (int i = 0; i < n; i++) ans += s[i] == '1';
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
