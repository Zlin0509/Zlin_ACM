//
// Created by Zlin on 2025/2/11.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

inline void Zlin()
{
    ll n, x, y;
    cin >> n >> x >> y;
    ll ans = 0;
    ll M = min(y, n);
    for (ll m = 0; m <= M; m++){
        ll A = x + m;
        ll R = n - m;
        ll maxAttack = A + (y - m);
        ll r_attack = min(R, maxAttack);
        ll v = min(y - m, r_attack);
        ll u = r_attack - v;
        ll damage = v * (A + 1) + (u * A - (u * (u - 1)) / 2);
        ans = max(ans, damage);
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
