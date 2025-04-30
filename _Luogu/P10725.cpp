#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 10, INF = 1e8;
int n, ans, c[N], dp[N][2];
vector<int> e[N];
void dfs(int u, int fa)
{
    dp[u][0] = dp[u][1] = -INF;
    dp[u][c[u]] = 0;
    for (auto v : e[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
        ans = max(ans, max(dp[u][1] + dp[v][0], dp[u][0] + dp[v][1]) + 1);
        dp[u][0] = max(dp[u][0], dp[v][0] + 1);
        dp[u][1] = max(dp[u][1], dp[v][1] + 1);
    }
    return;
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
    dfs(1, 0);
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