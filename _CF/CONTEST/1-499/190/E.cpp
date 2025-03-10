//
// Created by Zlin on 2025/1/19.
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

int n, m, ans;
vi f, nxt, siz, head;
set<int> have;
vector<bool> tag;
vector<vi> e;

inline int find(int u)
{
    return f[u] == u ? u : f[u] = find(f[u]);
}

inline void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx == fy)
        return;
    --ans;
    if (fx > fy)
        swap(fx, fy);
    f[fx] = fy;
}

inline bool dfs(int u, int top)
{
    if (!tag[u])
        return true;
    for (int i = head[u]; i; i = nxt[i])
        if (i > top && dfs(i, top))
            return true;
    return false;
}

inline void Zlin()
{
    cin >> n >> m;

    ans = n;
    siz.assign(n + 1, 0);
    f.assign(n + 1, 0);
    nxt.assign(n + 1, 0);
    head.assign(n + 1, 0);
    tag.assign(n + 1, false);
    e.assign(n + 1, vi());
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
        have.insert(i);
    }

    auto add_e = [&](int u, int v)
    {
        nxt[v] = head[u];
        head[u] = v;
    };

    for (int i = 1, u, v; i <= m; i++)
    {
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        e[u].push_back(v);
    }

    for (int i = 1, u, v; i <= n; i++)
    {
        if (have.empty())
            break;
        for (int x : e[i])
            tag[x] = true;

        auto it = have.end();
        --it;
        u = find(i);

        while (*it > i)
        {
            v = *it;
            if (v != u && dfs(v, i))
            {
                merge(u, v);
                add_e(max(u, v), min(u, v));
                if (u < v)
                {
                    have.erase(u);
                    u = v;
                }
                else
                {
                    ++it;
                    have.erase(v);
                }
            }
            if (it == have.begin())
                break;
            --it;
        }

        for (int x : e[i])
            tag[x] = false;
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        head[i] = 0;
    for (int i = 1; i <= n; i++)
        if (find(i) != i)
        {
            add_e(f[i], i);
            siz[f[i]]++;
        }
    for (int i = 1; i <= n; i++)
        if (find(i) == i)
        {
            cout << siz[i] + 1 << " " << i << ' ';
            for (int j = head[i]; j; j = nxt[j])
                cout << j << ' ';
            cout << endl;
        }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
