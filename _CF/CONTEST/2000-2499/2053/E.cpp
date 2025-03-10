//
// Created by Zlin on 2025/1/25.
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

int n;
vector<vi> e;
vi siz, tag, f;

inline void dfs(int u, int fa)
{
    f[u] = fa;
    siz[u] = !tag[u];
    for (int v : e[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
        siz[u] += siz[v];
    }
}

inline void Zlin()
{
    cin >> n;
    f.assign(n + 1, 0);
    siz.assign(n + 1, 0);
    tag.assign(n + 1, 0);
    e.assign(n + 1, vi());
    for (int i = 1, u, v; i < n; i++)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (e[i].size() == 1)
            ++cnt, tag[i] = tag[e[i][0]] = 1;
    ll ans = 1ll * cnt * (n - cnt);
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (e[i].size() == 1)
            continue;
        for (int j : e[i])
            if (j != f[i] && tag[j] && e[j].size() != 1)
                ans += siz[j];
        if (tag[f[i]] && e[f[i]].size() > 1)
            ans += siz[1] - siz[i];
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
