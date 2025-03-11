//
// Created by 27682 on 2025/3/11.
//

#include "bits/stdc++.h"
#define endl '\n'
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
    int n, m;
    cin >> n >> m;
    vll x(n), r(n);
    for (ll& it : x)
        cin >> it;
    for (ll& it : r)
        cin >> it;
    unordered_map<ll, ll> val;
    for (int i = 0; i < n; i++)
    {
        ll xx = x[i], rr = r[i];
        for (ll j = xx - rr; j <= xx + rr; j++)
            val[j] = max(val[j], (ll)sqrt(rr * rr - (xx - j) * (xx - j)));
    }
    ll ans = 0;
    unordered_map<ll, bool> used;
    for (int i = 0; i < n; i++)
    {
        ll xx = x[i], rr = r[i];
        for (ll j = xx - rr; j <= xx + rr; j++)
        {
            if (!used[j])
            {
                ans += val[j] * 2 + 1;
                used[j] = true;
            }
        }
    }
    cout << ans << endl;
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
