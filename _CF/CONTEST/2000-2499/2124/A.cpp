//
// Created by 27682 on 2025/7/6.
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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int tag = 0;
    for (int i = 0; i < n; i++) {
        if (tag > a[i]) {
            cout << "YES" << endl;
            cout << 2 << endl;
            cout << tag << ' ' << a[i] << endl;
            return;
        }
        tag = max(tag, a[i]);
    }
    cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
