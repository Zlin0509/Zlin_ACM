//
// Created by 27682 on 2025/7/17.
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

constexpr int N = 5e5 + 10;

int n, cnt[66];
ll a[N];

inline void Zlin() {
    for (int i = 0; i < 63; i++) cnt[i] = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int k = 0; k < 63; k++) {
            if (a[i] >> k & 1) {
                ++cnt[k];
            }
        }
    }
    for (int i = 0; i < 63; i++) {
        if (cnt[i] > 1) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}