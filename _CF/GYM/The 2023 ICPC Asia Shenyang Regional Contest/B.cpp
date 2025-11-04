//
// Created by 27682 on 2025/11/4.
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

inline void Zlin(int n) {
    vector<int> v(n), a(n + 1);
    iota(v.begin(), v.end(), 1);
    ll ans = 0;
    do {
        for (int i = 0; i < n; i++) a[v[i]] = i + 1;
        bool check = true;
        for (int i = 2; i < n; i++) {
            if ((a[i] - a[i - 1]) * (a[i] - a[i + 1]) <= 0) {
                check = false;
                break;
            }
        }
        if (check) {
            // for (int i = 1; i <= n; i++) cout << a[i] << ' ';
            // cout << endl;
            ++ans;
        }
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    for (int i = 3; i <= 10; i++) {
        Zlin(i);
    }
    return 0;
}
