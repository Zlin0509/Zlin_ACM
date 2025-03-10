//
// Created by 27682 on 2025/3/4.
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

int n, q;
vector<vi> e;
vi c, f, d;

inline void dfs(int u, int fa)
{
    f[u] = fa;
    if (c[u])
        --d[u], ++d[fa];
    for (int v : e[u])
        if (v != fa)
            dfs(v, u);
}

inline void Zlin()
{
    cin >> n >> q;
    e.assign(n + 1, vi());
    f.assign(n + 1, 0);
    d.assign(n + 1, 0);
    c.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1, u, v; i < n; i++)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    set<int> l, r;
    for (int i = 0; i <= n; i++)
    {
        if (d[i] == 1)
            r.insert(i);
        if (d[i] == -1)
            l.insert(i);
    }
    while (q--)
    {
        int u;
        cin >> u;
        if (c[u])
        {
            ++d[u];
            --d[f[u]];
            if (d[u] == 2)
                r.erase(u);
            if (d[u] == 1)
                r.insert(u);
            if (d[u] == 0)
                l.erase(u);
            if (d[u] == -1)
                l.insert(u);
            if (d[f[u]] == -2)
                l.erase(f[u]);
            if (d[f[u]] == -1)
                l.insert(f[u]);
            if (d[f[u]] == 0)
                r.erase(f[u]);
            if (d[f[u]] == 1)
                r.insert(f[u]);
        }
        else
        {
            --d[u];
            ++d[f[u]];
            if (d[u] == -2)
                l.erase(u);
            if (d[u] == -1)
                l.insert(u);
            if (d[u] == 0)
                r.erase(u);
            if (d[u] == 1)
                r.insert(u);
            if (d[f[u]] == 2)
                r.erase(f[u]);
            if (d[f[u]] == 1)
                r.insert(f[u]);
            if (d[f[u]] == 0)
                l.erase(f[u]);
            if (d[f[u]] == -1)
                l.insert(f[u]);
        }
        c[u] ^= 1;
        bool check = false;
        if (l.size() == 1 && r.size() == 1)
            check = true;
        if (l.size() == 2 && r.size() == 2)
        {
            int x = *r.begin(), y = *prev(r.end());
            check = (f[x] == y || f[y] == x) && c[x] != c[y];
        }
        cout << (check ? "Yes" : "No") << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--)
        Zlin();
    return 0;
}
