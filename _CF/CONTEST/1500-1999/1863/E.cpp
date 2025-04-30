//
// Created by Zlin on 2024/11/5.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int N = 2e5 + 10;
constexpr int inf = 1e9;

int n, m, k;
ll h[N], change[N], mx[N];
int in[N];
vi e[N], e1[N];
vector<pll> have;

inline ll dfs(int u) {
    if (change[u] != inf)
        return change[u];
    if (e1[u].empty())
        return change[u] = h[u];
    for (int v: e1[u])
        if (h[u] - h[v] < k)
            change[u] = min(change[u], dfs(v));
    return change[u];
}

inline void topo() {
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!in[i])
            q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: e[u]) {
            if (h[v] < h[u])
                h[v] += (h[u] - h[v] + k - 1) / k * k;
            --in[v];
            if (!in[v])
                q.push(v);
        }
    }
    for (int i = 1; i <= n; i++)
        if (e[i].empty())
            have.push_back({dfs(i), h[i]});
}

inline void Zlin() {
    cin >> n >> m >> k;
    have.clear();
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        e[i].clear();
        e1[i].clear();
        in[i] = mx[i] = 0;
        change[i] = inf;
    }
    for (int i = 1, a, b; i <= m; i++) {
        cin >> a >> b;
        e[a].push_back(b);
        ++in[b];
        e1[b].push_back(a);
    }
    topo();
    sort(have.begin(), have.end());
    for (int i = have.size() - 1; i >= 0; i--)
        mx[i] = max(mx[i + 1], have[i].second);
    ll ans = 1e16, l = 0, r = 0;
    for (int i = 0; i < have.size();) {
        ans = min(ans, max(r, mx[i]) - have[i].first);
        l = have[i].first;
        while (i < have.size() && have[i].first == l) {
            r = max(r, have[i].second + k);
            ++i;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
