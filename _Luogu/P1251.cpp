//
// Created by 27682 on 2025/6/24.
//
#include <bits/stdc++.h>
#define endl '\n'
#define in(i) ((i) * 2 - 1)
#define out(i) ((i) * 2)
using namespace std;

typedef long long ll;

static const int INF = 1e8;

vector<int> path;

struct MCMF {
    static const int N = 5e3 + 5, M = 1e5 + 5;
    int tot = 1, lnk[N], cur[N], ter[M], nxt[M], cap[M], cost[M];
    ll dis[N], ret;
    bool vis[N];

    void init(int n) {
        tot = 1;
        memset(lnk, 0, sizeof(int) * (n + 2));
        ret = 0;
    }

    void add(int u, int v, int w, int c) {
        ter[++tot] = v, nxt[tot] = lnk[u], lnk[u] = tot, cap[tot] = w, cost[tot] = c;
    }

    void addedge(int u, int v, int w, int c) { add(u, v, w, c), add(v, u, 0, -c); }

    bool spfa(int s, int t) {
        memset(dis, 0x3f, sizeof(dis));
        memcpy(cur, lnk, sizeof(lnk));
        queue<int> q;
        q.push(s), dis[s] = 0, vis[s] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop(), vis[u] = false;
            for (int i = lnk[u]; i; i = nxt[i]) {
                int v = ter[i];
                if (cap[i] && dis[v] > dis[u] + cost[i]) {
                    dis[v] = dis[u] + cost[i];
                    if (!vis[v]) q.push(v), vis[v] = true;
                }
            }
        }
        return dis[t] != dis[N - 1];
    }

    int dfs(int u, int t, int flow) {
        if (u == t) return flow;
        vis[u] = true;
        int ans = 0;
        for (int &i = cur[u]; i && ans < flow; i = nxt[i]) {
            int v = ter[i];
            if (!vis[v] && cap[i] && dis[v] == dis[u] + cost[i]) {
                int x = dfs(v, t, min(cap[i], flow - ans));
                if (x) ret += x * cost[i], cap[i] -= x, cap[i ^ 1] += x, ans += x;
            }
        }
        vis[u] = false;
        return ans;
    }

    int dinic(int s, int t) {
        int ans = 0;
        while (spfa(s, t)) {
            int x;
            while ((x = dfs(s, t, INF))) ans += x;
        }
        return ans;
    }
} mcmf;

static const int MAXN = 10010;

int N, r[MAXN];
int p, m, f, n, s;

inline void Zlin() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> r[i];
    cin >> p >> m >> f >> n >> s;
    mcmf.init(N * 2 + 2);
    int S = N * 2 + 1, T = N * 2 + 2;
    for (int i = 1; i <= N; i++) {
        mcmf.addedge(S, in(i), r[i], 0);
        mcmf.addedge(out(i), T, r[i], 0);
        mcmf.addedge(S, out(i), INF, p);
        if (i < N) mcmf.addedge(in(i), in(i + 1), INF, 0);
        if (i + m <= N) mcmf.addedge(in(i), out(i + m), INF, f);
        if (i + n <= N) mcmf.addedge(in(i), out(i + n), INF, s);
    }
    mcmf.dinic(S, T);
    cout << mcmf.ret << endl;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
