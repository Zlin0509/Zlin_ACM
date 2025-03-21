//
// Created by 27682 on 2025/3/21.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct node
{
    int x, y;
};

inline void Zlin()
{
    int n, m;
    cin >> n >> m;
    vector<node> a(n), b(m);
    ll l = 1e12, r = -1e12, lx = 1e12, rx = -1e12;
    for (auto& [x, y] : a)
    {
        cin >> x >> y;
        l = min(l, ll(y + x));
        r = max(r, ll(y + x));
        lx = min(lx, ll(y - x));
        rx = max(rx, ll(y - x));
    }
    ll ans = 1e12, val;
    for (auto& [x, y] : b)
    {
        cin >> x >> y;
        val = max(abs(r - y - x), abs(l - y - x));
        val = max(val, abs(lx - y + x));
        val = max(val, abs(rx - y + x));
        ans = min(ans, val);
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
