//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
mt19937 rnd(time(0));
const int inf = 1e15;
const int N = 2e5 + 7;
vector<pair<int, int> > g[N];
int val[N], vis1[N];
ll ans = 0;
vector<vi> group;

bool dfs(int x, int fa, int pos, int now) {
    if (vis1[x]) return now == val[x];
    vis1[x] = true;
    val[x] = now;
    for (auto [y,w]: g[x]) {
        if (y == fa) continue;
        if (!dfs(y, x, pos, w >> pos & 1 ^ now)) return false;
    }
    return true;
}

int vis[N];

inline void dfs1(int u, vi &now) {
    now.push_back(u);
    vis[u] = 1;
    for (auto [v, w]: g[u]) {
        if (vis[v]) continue;
        dfs1(v, now);
    }
}

void solved() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vi now;
        dfs1(i, now);
        group.push_back(now);
    }
    for (int i = 1; i <= 30; i++) {
        //计算第i位的贡献
        for (vi &now: group) {
            for (int v: now) val[v] = vis1[v] = 0;
            if (!dfs(now[0], 0, i - 1, 0)) {
                cout << -1 << endl;
                return;
            }
            ll tem1 = 0, tem2 = 0;
            for (int v: now) {
                tem1 += val[v] * (1 << (i - 1));
                val[v] = vis1[v] = 0;
            }
            dfs(now[0], 0, i - 1, 1);
            for (int v: now) {
                tem2 += val[v] * (1 << (i - 1));
                val[v] = vis1[v] = 0;
            }
            ans += min(tem1, tem2);
        }
    }
    cout << ans << '\n';
}

signed main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin>>_;
    while (_--)solved();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.";
    return 0;
}
