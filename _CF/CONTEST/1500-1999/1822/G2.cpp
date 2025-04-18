//
// Created by 27682 on 2025/4/16.
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

map<ll, int> mp;

inline void Zlin() {
    mp.clear();
    int n;
    cin >> n;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        mp[x]++;
    }
    ll ans = 0, i, l, r;
    for (auto [it, val]: mp) {
        if (val >= 3) ans += 1ll * val * (val - 1) * (val - 2);
        if (it <= 1e6) {
            ll z = sqrt(it);
            for (i = 1; i <= z; i++) {
                if (it % i) continue;
                l = it / i;
                r = it * i;
                if (l != it && r != it && l != r && mp.count(l) && mp.count(r)) ans += 1ll * mp[l] * val * mp[r];
                if (i * i != it) {
                    l = it / (it / i);
                    r = it * (it / i);
                    if (l != it && r != it && l != r && mp.count(l) && mp.count(r)) ans += 1ll * mp[l] * val * mp[r];
                }
            }
        } else {
            for (i = 2; i * it <= 1e9; i++) {
                if (it % i) continue;
                l = it / i;
                r = it * i;
                if (l != it && r != it && l != r && mp.count(l) && mp.count(r)) ans += 1ll * mp[l] * val * mp[r];
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
