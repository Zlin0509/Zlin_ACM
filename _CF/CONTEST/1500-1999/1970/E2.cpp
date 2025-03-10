//
// Created by 27682 on 2025/3/5.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr ll mo = 1e9 + 7;

int m, n;
vi l, r;

vector<vll> f, a;

inline vector<vll> mul(vector<vll>& x, vector<vll>& y)
{
    vector<vll> res;
    res.assign(m + 1, vll(m + 1, 0));
    for (int k = 1; k <= m; k++)
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= m; j++)
                res[i][j] = (res[i][j] + 1ll * x[i][k] * y[k][j]) % mo;
    return res;
}

inline void Zlin()
{
    cin >> m >> n;
    l.assign(m + 1, 0);
    r.assign(m + 1, 0);
    for (int i = 1; i <= m; i++)
        cin >> l[i];
    for (int i = 1; i <= m; i++)
        cin >> r[i];
    f.assign(m + 1, vll(m + 1, 0));
    a.assign(m + 1, vll(m + 1, 0));
    f[1][1] = 1;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = 1ll * (l[i] + r[i]) * (l[j] + r[j]) - 1ll * r[i] * r[j];
    while (n)
    {
        if (n & 1)
            f = mul(f, a);
        a = mul(a, a);
        n >>= 1;
    }
    ll ans = 0;
    for (int i = 1; i <= m; i++)
        ans = (ans + f[1][i]) % mo;
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--)
        Zlin();
    return 0;
}
