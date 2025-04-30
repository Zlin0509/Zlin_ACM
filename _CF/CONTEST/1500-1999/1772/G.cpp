//
// Created by 27682 on 2025/4/23.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline void Zlin() {
    int n;
    ll x, y, ans = 0;
    cin >> n >> x >> y;
    vll a(n);
    for (ll &it: a) cin >> it;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) a[i] -= i;
    for (int i = 1; i < n; i++) a[i] = max(a[i], a[i - 1]);
    vll sx;
    map<ll, int> mp;
    for (ll it: a) {
        sx.push_back(it);
        mp[it]++;
    }
    sort(sx.begin(), sx.end());
    sx.erase(unique(sx.begin(), sx.end()), sx.end());
    for (int i = 1; i < sx.size(); i++) mp[sx[i]] += mp[sx[i - 1]];
    if (sx[0] > x) {
        cout << -1 << endl;
        return;
    }
    while (1) {
        int pos = upper_bound(sx.begin(), sx.end(), x) - sx.begin();
        if (pos == sx.size()) {
            cout << ans + y - x << endl;
            return;
        }
        int val = mp[sx[pos - 1]];
        if (x + val >= y) {
            cout << ans + y - x << endl;
            return;
        }
        int val1 = val * 2 - n;
        if (val1 <= 0) {
            cout << -1 << endl;
            return;
        }
        ll dif = min(sx[pos] - x + val1 - 1, y - x - val + val1 - 1) / val1;
        ans += dif * n;
        x += dif * val1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    for (int i = 1; i <= ttt; i++)
        Zlin();
    return 0;
}
