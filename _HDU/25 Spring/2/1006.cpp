//
// Created by 27682 on 2025/3/14.
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

struct node
{
    int r, b, m;

    bool operator<(const node& x) const
    {
        if (r != x.r) return r < x.r;
        if (b != x.b) return b < x.b;
        return m < x.m;
    }
};

map<node, int> f;

inline int dfs(node u)
{
    if (f[u])
        return f[u];
    set<int> now;
    auto [r,b,m] = u;
    for (int i = 1; i <= min(3, r); i++)
        now.insert(dfs({r - i, b, m}));
    if (b)
    {
        now.insert(dfs({r + 1, b - 1, m}));
        now.insert(dfs({r, b - 1, m}));
        if (r)
            now.insert(dfs({r - 1, b - 1, m}));
        if (b >= 2)
            now.insert(dfs({r + 1, b - 2, m}));
    }
    if (m)
    {
        now.insert(dfs({r + 1, b, m - 1}));
        now.insert(dfs({r, b + 1, m - 1}));
        now.insert(dfs({r + 1, b + 1, m - 1}));
    }
    int tag = 0;
    while (!now.empty() && *now.begin() == tag)
    {
        ++tag;
        now.erase(now.begin());
    }
    return f[u] = tag;
}

inline void Zlin()
{
    int r, b, m;
    cin >> r >> b >> m;
    if (r & 1)
    {
        cout << "Alice" << endl;
        return;
    }
    if (r >> 1 & 1)
    {
        cout << (b & 1 ? "Bob" : "Alice") << endl;
        return;
    }
    cout << (b & 1 ? "Alice" : "Bob") << endl;
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
