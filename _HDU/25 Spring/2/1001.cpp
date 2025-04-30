//
// Created by 27682 on 2025/3/14.
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

constexpr ll mo = 1e16 + 1029;

vector<ull> a(64);

inline void Zlin()
{
    int n, q;
    cin >> n >> q;
    vector<ull> x(n);
    for (ull& it : x)
        cin >> it;
    x.push_back(0);
    x.push_back((1ull << 64) - 1);
    for (int i = 0; i < 64; i++)
    {
        a[i] = -1ull;
        for (ull it : x)
            if (it >> i & 1)
                a[i] &= it;
    }
    ll ans = 0;
    while (q--)
    {
        ll tag, res = -1ull;
        cin >> tag;
        for (int i = 0; i < 64; i++)
            if (tag >> i & 1)
                res &= a[i];
        res %= mo;
        ans = ans ^ res;
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
