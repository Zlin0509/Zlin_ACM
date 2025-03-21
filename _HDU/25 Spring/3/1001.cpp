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


constexpr ll mo = 998244353;
const int N = 10;
long long C[N + 1][N + 1];

void init_comb()
{
    for (int i = 0; i <= N; ++i)
    {
        C[i][0] = C[i][i] = 1; // 边界条件
        for (int j = 1; j < i; ++j)
        {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j]; // 递推公式
        }
    }
}

ll ss[4] = {1, 2, 2, 4};

unordered_map<int, int> val;

int dfs(int dep, int x)
{
    if (x > dep && val[dep])
        return val[dep];
    ll res = 0;
    if (dep < 4)
    {
        return res;
    }
    int len = 1;
    while (len << 1 <= dep)
        len <<= 1;
    if (x - 1 >= len)
    {
        res += dfs(dep - len, len - 1);
        x -= len;
    }
    res += dfs(dep - len, x);
    return res;
}

inline void Zlin()
{
    int n;
    cin >> n;
    vll a(n), l(n);
    for (ll& it : a)
        cin >> it;
    for (ll& it : l)
        cin >> it;
    ll ans = 1;
    for (int i = 0; i < n; i++)
    {
        ll cnt = 0;
        l[i] = min(l[i], a[i]);
        if (a[i] <= 7)
        {
            for (int j = 0; j <= l[i]; j++)
                cnt += C[a[i]][j] & 1;
            ans = ans * cnt % mo;
            continue;
        }
        cnt = dfs(a[i], l[i]);
        ans = ans * cnt % mo;
    }
    cout << ans << endl;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    init_comb();
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
