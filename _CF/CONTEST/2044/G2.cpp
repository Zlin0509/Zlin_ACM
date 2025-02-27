//
// Created by Zlin on 2025/2/25.
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
vi f, vis, dep, tag;

vi cur;

inline int dfs(int u)
{
    vis[u] = 1;
    cur.push_back(u);
    int v = f[u];
    if (vis[v] == 1)
    {
        while (cur.back() != v)
        {
            tag[cur.back()] = 1;
            cur.pop_back();
        }
        tag[cur.back()] = 1;
        cur.pop_back();
        return 1;
    }
    if (vis[v] == 0 && dfs(v))
        return 1;
    vis[u] = 2;
    cur.pop_back();
    return 0;
}

inline void Zlin()
{
    cin >> n;
    cur.clear();
    f.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    dep.assign(n + 1, 0);
    tag.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> f[i];
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i);
    for (int i = 1; i <= n; i++)
        cout << tag[i] << ' ';
    cout << endl;
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
