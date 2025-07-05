//
// Created by 27682 on 2025/7/5.
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
    ll n;
    cin >> n;
    ll xa, xb, ya, yb;
    cin >> xa >> ya >> xb >> yb;
    vll a(n);
    for (ll &it: a) cin >> it;
    ll dif = (xa - xb) * (xa - xb) + (ya - yb) * (ya - yb);
    if (n == 1) {
        cout << (a[0] * a[0] == dif ? "Yes" : "No") << endl;
    } else {
        ll sum = 0;
        for (ll it: a) sum += it;
        if (sum * sum < dif) {
            cout << "No" << endl;
            return;
        }
        sort(a.begin(), a.end());
        sum = a.back() * 2 - sum;
        if (sum > 0 && sum * sum > dif) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
