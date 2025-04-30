#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 10;
int n, ans, c[N];
vector<int> e[N];
inline bool dfs(int u, int fa)
{
    bool check;
    c[u] ? check = true : check = false;
    for (auto v : e[u])
        if (v != fa && dfs(v, u))
            check = true;
    if (check && !c[u])
        c[u] = 1, ++ans;
    return check;
}
inline void Zlin()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1, u, v; i < n; i++)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    ans = 0;
    for (int i = 1; i <= n; i++)
        if (c[i])
        {
            dfs(i, 0);
            break;
        }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Zlin();
    return 0;
}