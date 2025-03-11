//
// Created by 27682 on 2025/3/11.
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

constexpr int N = 2e5 + 10;

int n, fa[N], dep[N], siz[N], dfn[N], tot = 0;
vi e[N];
vi a[N];

inline void dfs(int u, int fa)
{
    dfn[u] = ++tot;
    siz[u] = 1;
    a[dep[u]].push_back(dfn[u]);
    for (int v : e[u])
    {
        if (v == fa)
            continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
        siz[u] += siz[v];
    }
}

inline void Zlin()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> fa[i];
        e[fa[i]].push_back(i);
    }
    dfs(1, 0);
    int q;
    cin >> q;
    while (q--)
    {
        int u, d;
        cin >> u >> d;
        int l, r;
        l = dfn[u], r = dfn[u] + siz[u] - 1;
        cout << upper_bound(a[d].begin(), a[d].end(), r) - lower_bound(a[d].begin(), a[d].end(), l) << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
