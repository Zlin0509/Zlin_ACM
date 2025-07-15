#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 8e5 + 5;
const int M = 1e6 + 1;
const ll inf = 1e18;
const ll mod = 998244353;
ll n, m, d[N];
ll g[N][4];
vector<pair<ll, ll> > v, g2[N];

ll get(ll x, ll fa) {
    for (int i = 1; i <= d[x]; i++) {
        if (g[x][i] == fa) return i;
    }
}

ll getidx(pair<ll, ll> x) {
    if (x.first > x.second) swap(x.first, x.second);
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

ll getid(ll x, ll id) {
    return (id - 1) * n + x;
}

bool vis[N];
//每次使用清空scc_cnt,dfn[N],idx,top
ll sz[N], val[N], id[N], dfn[N], low[N], idx;
ll stk[N], in_stk[N], scc_cnt, top;
// idx: 时间戳
// dfn[x]: 表示x点的时间戳
// low[x]: 表示x点所在的强连通分量的点中最小时间戳（即最高点的时间戳）
// id[x]: 表示x点所在强连通分量的编号
// sz[N]: 每个强连通分量的大小
// val[N]: 每个强连通分量的权值
void tarjan(ll xx, ll id1) {
    ll x = getid(xx, id1);
    dfn[x] = low[x] = ++idx;
    stk[++top] = x; //将该点加入栈中
    in_stk[x] = 1; //x是否在栈内
    // cout << xx << " " << id1 << "\n";
    id1 = (id1 + 1) % d[xx];
    if (!id1) id1 = d[xx];
    ll y = g[xx][id1];
    ll id2 = get(y, xx);
    ll v = getid(y, id2);
    if (!dfn[v]) {
        tarjan(y, id2);
        low[x] = min(low[x], low[v]);
    } else if (in_stk[v]) {
        low[x] = min(low[x], low[v]);
    }
    if (dfn[x] == low[x]) {
        int y;
        ++scc_cnt;
        do {
            y = stk[top--];
            in_stk[y] = 0;
            sz[scc_cnt]++;
            id[y] = scc_cnt;
        } while (y != x);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        for (int j = 1; j <= d[i]; j++) {
            cin >> g[i][j];
            ll x = g[i][j], y = i;
            // if(x>y) swap(x,y);
            // v.push_back({x,y});
        }
    }
    // sort(v.begin(),v.end());
    // v.erase(unique(v.begin(),v.end()),v.end());
    // tarjan(1,d[1]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= d[i]; j++) {
            if (dfn[getid(i, j)]) continue;
            idx = top = 0;
            tarjan(i, j);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= d[i]; j++) {
            ll x = i, y = g[i][j];
            if (x > y) swap(x, y);
            g2[id[getid(i, j)]].push_back({x, y});
        }
    }
    for (int i = 1; i <= scc_cnt; i++) {
        sort(g2[i].begin(), g2[i].end());
        g2[i].erase(unique(g2[i].begin(), g2[i].end()), g2[i].end());
    }
    // cout << scc_cnt << "\n";
    // cout << g2[1].size() << "\n";
    for (int i = 1; i <= n; i++) {
        ll x = id[getid(i, d[i])];
        // cout << x << "\n";
        cout << g2[x].size() << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _ = 1; // cin >> _;
    while (_--) solve();
    return 0;
}
