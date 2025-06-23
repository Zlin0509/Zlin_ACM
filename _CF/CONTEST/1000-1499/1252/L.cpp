//
// Created by 27682 on 2025/6/23.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int N = 2010;
constexpr int INF = 0x3f3f3f3f;

int S, T;
int m_to[N];

struct MF {
    struct edge {
        int v, nxt, cap, flow;
    } e[N * N * 2];

    int fir[N * 3], cnt;

    int nx, mx;
    int n;
    ll maxflow = 0;
    int dep[N * 3], cur[N * 3];

    void init() {
        memset(fir, -1, sizeof fir);
        cnt = 0;
    }

    void addedge(int u, int v, int c) {
        e[cnt] = {v, fir[u], c, 0};
        fir[u] = cnt++;
        e[cnt] = {u, fir[v], 0, 0};
        fir[v] = cnt++;
    }

    bool bfs() {
        queue<int> q;
        memset(dep, 0, sizeof(int) * (n + 1));

        dep[S] = 1;
        q.push(S);
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int i = fir[u]; ~i; i = e[i].nxt) {
                int v = e[i].v;
                if (!dep[v] && e[i].cap > e[i].flow) {
                    dep[v] = dep[u] + 1;
                    q.push(v);
                }
            }
        }
        return dep[T];
    }

    int dfs(int u, int flow) {
        if (!flow || u == T) return flow;
        int ret = 0;
        for (int &i = cur[u]; ~i; i = e[i].nxt) {
            int v = e[i].v, d;
            if (dep[v] == dep[u] + 1 && (d = dfs(v, min(flow - ret, e[i].cap - e[i].flow)))) {
                if (u >= 1 && u <= mx && v >= mx + 1 && v <= mx + nx) m_to[u] = v - mx;
                ret += d;
                e[i].flow += d;
                e[i ^ 1].flow -= d;
                if (ret == flow) return ret;
            }
        }
        return ret;
    }

    void dinic() {
        while (bfs()) {
            memcpy(cur, fir, sizeof(int) * (n + 1));
            maxflow += dfs(S, INF);
        }
    }
} mf;

int n, m, c[N], to[N], cir[N];
vi e[N], mx, b[N], M[10010];

int op[N], cir_siz = 0;
vi stk;

inline void dfs(int u, int fa) {
    stk.push_back(u);
    op[u] = 1;
    for (int v: e[u]) {
        if (v == fa) continue;
        if (op[v] == 1) {
            int lx = stk.size() - 1;
            while (stk[lx] != v) cir[stk[lx--]] = 1, ++cir_siz;
            ++cir_siz;
            cir[v] = 1;
        } else if (!op[v]) dfs(v, u);
    }
    op[u] = 2;
    stk.pop_back();
}

inline void Zlin() {
    cin >> n >> m;
    mf.init();
    S = 0, T = n + m + 2;
    mf.nx = n, mf.mx = m, mf.n = n + m + 2;
    for (int i = 1, siz; i <= n; i++) {
        cin >> to[i];
        e[i].push_back(to[i]);
        e[to[i]].push_back(i);
        cin >> siz;
        b[i].assign(siz, 0);
        for (int &it: b[i]) {
            cin >> it;
            mx.push_back(it);
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> c[i];
        mx.push_back(c[i]);
    }
    sort(mx.begin(), mx.end());
    mx.erase(unique(mx.begin(), mx.end()), mx.end());
    for (int i = 1; i <= n; i++) {
        for (int &it: b[i]) {
            it = lower_bound(mx.begin(), mx.end(), it) - mx.begin();
            M[it].push_back(i);
        }
    }
    for (int i = 1; i <= m; i++) {
        c[i] = lower_bound(mx.begin(), mx.end(), c[i]) - mx.begin();
        mf.addedge(S, i, 1);
        for (int v: M[c[i]]) mf.addedge(i, v + m, 1);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        if (cir[i]) mf.addedge(i + m, n + m + 1, 1);
        else mf.addedge(i + m, T, 1);
    }
    mf.addedge(n + m + 1, T, cir_siz - 1);
    mf.dinic();
    if (mf.maxflow != n - 1) {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= m; i++) cout << m_to[i] << ' ' << to[m_to[i]] << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
