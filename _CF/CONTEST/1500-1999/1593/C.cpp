//
// Created by Zlin on 2025/8/22.
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

constexpr int N = 4e5 + 10;

int n, k, a[N];

inline bool check(int pos) {
    ll cat = 0;
    for (int i = pos; i <= k; i++) {
        cat += 1ll * (a[i + 1] - a[i]) * (i - pos + 1);
        if (cat >= a[i + 1]) return false;
    }
    return true;
}

inline void Zlin() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++) cin >> a[i];
    a[k + 1] = n;
    sort(a + 1, a + k + 1);
    int l = 1, r = k, mid;
    while (l < r) {
        mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << k - l + 1 << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
