#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
const int M = 10;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
ll n, m;

struct Node {
    ll x, w;
};

vector<Node> g[N], g2[N];
ll sz[N], val[N], id[N], dfn[N], low[N], idx;
ll stk[N], in_stk[N], scc_cnt, top, dp[N];
ll sum = 0;
ll ans = 0;

void tarjan(ll x, ll fa) {
    dfn[x] = low[x] = ++idx;
    stk[++top] = x; //将该点加入栈中
    in_stk[x] = 1; //x是否在栈内
    for (auto o: g[x]) {
        ll v = o.x;
        if (v == fa) continue;
        if (!dfn[v]) {
            tarjan(v, x);
            low[x] = min(low[x], low[v]);
        } else if (in_stk[v]) {
            low[x] = min(low[x], low[v]);
        }
    }
    if (dfn[x] == low[x]) {
        int y;
        ++scc_cnt;
        do {
            y = stk[top--];
            in_stk[y] = 0;
            id[y] = scc_cnt;
        } while (y != x);
    }
}

void dfs(ll x, ll fa) {
    dp[x] = 0;
    for (auto [v, w]: g2[x]) {
        if (v == fa) continue;
        dfs(v, x);
        dp[x] += dp[v] + 1;
        if (dp[v] % 2 == 0) ans = max(ans, sum - w);
    }
}

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        ll x, y, w;
        cin >> x >> y >> w;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
        sum += w;
    }
    if (m % 2 == 0) {
        cout << sum << "\n";
        return;
    }
    tarjan(1, 0);
    for (int i = 1; i <= n; i++) {
        ll x = id[i];
        for (auto [v, w]: g[i]) {
            if (id[v] == x) {
                ans = max(ans, sum - w);
                sz[x]++;
            } else g2[x].push_back({id[v], w});
        }
    }
    for (int i = 1; i <= scc_cnt; i++) sz[i] /= 2;
    dfs(1, 0);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1; //cin >> _;
    while (_--) solve();
    return 0;
}
