//
// Created by Zlin on 2025/1/18.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int used[1010][1010]{};

int n;
vi f, vis;
vector<vi> e;

unordered_set<int> have;

struct Op
{
    int i, j, u, v;
};

vector<Op> ans;

inline int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }

inline void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    f[fx] = fy;
}

inline void dfs(int u, int fa)
{
    vis[u] = 1;
    for (int v : e[u])
    {
        if (v == fa || used[u][v] || used[v][u])
            continue;
        if (vis[v])
        {
            for (auto it : have)
            {
                if (find(it) == find(u)) continue;
                merge(it, u);
                ans.push_back({u, v, v, it});
                break;
            }
            used[u][v] = used[v][u] = 1;
        }
        else dfs(v, u);
    }
}

inline void Zlin()
{
    cin >> n;
    e.assign(n + 2, vi());
    f.assign(n + 2, 0);
    vis.assign(n + 2, 0);
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1, u, v; i < n; i++)
    {
        cin >> u >> v;
        merge(u, v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        f[i] = find(i), have.insert(f[i]);

    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i, 0);

    cout << ans.size() << '\n';
    for (Op it : ans)
        cout << it.i << ' ' << it.j << ' ' << it.u << ' ' << it.v << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
