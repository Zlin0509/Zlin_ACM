//
// Created by 27682 on 2025/4/11.
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

inline void Zlin()
{
    int n;
    cin >> n;
    vll a(n), b(n);
    for (ll &it: a) cin >> it;
    for (ll &it: b) cin >> it;
    queue<int> lx;
    for (int i = 1; i < n; i++) {
        if (a[i] + b[i] != a[i - 1] + b[i - 1])
            lx.push(i);
    }
    lx.push(n);
    ll ans = 0;
    for (int i = 1; i < n; i++) a[i] += a[i - 1];
    for (int l = 0, r; l < n; l++) {
        if (lx.front() == l) lx.pop();
        r = lx.front();
        ans = max(ans, 1ll * (r - l) * (a[r - 1] - (l ? a[l - 1] : 0)));
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}