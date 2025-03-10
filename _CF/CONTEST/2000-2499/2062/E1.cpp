//
// Created by Zlin on 2025/2/22.
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
vi a, tag, dfn;
vector<vi> e;

struct Ftree
{
private:
    vi t;

public:
    void init(int n)
    {
        t.assign(n + 1, 0);
    }

    void upd(int i, int v)
    {
        while (i < t.size())
        {
            t[i] += v;
            i += i & -i;
        }
    }

    int qry1(int i)
    {
        int s = 0;
        while (i > 0)
        {
            s += t[i];
            i -= i & -i;
        }
        return s;
    }

    int qry2(int l, int r)
    {
        return qry1(r) - qry1(l - 1);
    }
} t;

inline void dfs(int u, int fa)
{
    int now = t.qry2(a[u] + 1, n);
    t.upd(a[u], 1);
    for (int v : e[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
    }
    if (tag[u] == t.qry2(a[u] + 1, n) - now)
        tag[u] = 0;
    else
        tag[u] = 1;
}

inline void Zlin()
{
    cin >> n;
    a.assign(n + 1, 0);
    tag.assign(n + 1, 0);
    dfn.assign(n + 1, 0);
    e.assign(n + 1, vi());
    t.init(n);
    for (int i = 1; i <= n; i++)
        cin >> a[i], dfn[i] = i, t.upd(a[i], 1);
    for (int i = 1; i <= n; i++)
        tag[i] = t.qry2(a[i] + 1, n);
    for (int i = 1, u, v; i < n; i++)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    sort(dfn.begin() + 1, dfn.end(), [&](int u, int v)
    {
        return a[u] > a[v];
    });
    for (int i = 1; i <= n; i++)
        if (tag[dfn[i]])
        {
            cout << dfn[i] << endl;
            return;
        }
    cout << 0 << endl;
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
