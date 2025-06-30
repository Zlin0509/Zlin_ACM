//
// Created by 27682 on 2025/6/30.
//
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

constexpr int S = 0, T1 = 3001, T2 = 3002, T = 3003;

int tag[3001];

struct MCMF {
    static const int N = 4e3 + 5, M = 1e5 + 5;
    static const int INF = 0x3f3f3f3f;
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
        memset(dis, -INF, sizeof(dis));
        memcpy(cur, lnk, sizeof(lnk));
        queue<int> q;
        q.push(s), dis[s] = 0, vis[s] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop(), vis[u] = false;
            for (int i = lnk[u]; i; i = nxt[i]) {
                int v = ter[i];
                if (cap[i] && dis[v] < dis[u] + cost[i]) {
                    dis[v] = dis[u] + cost[i];
                    if (!vis[v]) q.push(v), vis[v] = true;
                }
            }
        }
        return dis[t] != dis[N - 1];
    }

    vector<int> path;

    int dfs(int u, int t, int flow) {
        if (u == t) {
            for (int i = 0; i < path.size() - 1; i++) {
                if (path[i] >= 1 && path[i] <= 3000) {
                    if (path[i + 1] == T1) {
                        tag[path[i]] = 1;
                    } else if (path[i + 1] == T2) {
                        tag[path[i]] = 2;
                    } else {
                        tag[path[i]] = 0;
                    }
                }
            }
            return flow;
        }
        path.push_back(u);
        vis[u] = true;
        int ans = 0;
        for (int &i = cur[u]; i && ans < flow; i = nxt[i]) {
            int v = ter[i];
            if (!vis[v] && cap[i] && dis[v] == dis[u] + cost[i]) {
                int x = dfs(v, t, min(cap[i], flow - ans));
                if (x) ret += x * cost[i], cap[i] -= x, cap[i ^ 1] += x, ans += x;
            }
        }
        path.pop_back();
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

inline void Zlin() {
    int n, p, s;
    cin >> n >> p >> s;
    vector<pair<int, int> > v(n);
    for (int i = 0; i < n; i++) cin >> v[i].first;
    for (int i = 0; i < n; i++) cin >> v[i].second;
    mcmf.init(3000);
    for (int i = 0; i < n; i++) {
        mcmf.addedge(S, i + 1, 1, 0);
        mcmf.addedge(i + 1, T1, 1, v[i].first);
        mcmf.addedge(i + 1, T2, 1, v[i].second);
    }
    mcmf.addedge(T1, T, p, 0);
    mcmf.addedge(T2, T, s, 0);
    mcmf.dinic(S, T);
    vector<int> a, b;
    for (int i = 1; i <= n; i++) {
        if (tag[i] == 1) a.push_back(i);
        if (tag[i] == 2) b.push_back(i);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << mcmf.ret << endl;
    for (int it: a) cout << it << ' ';
    cout << endl;
    for (int it: b) cout << it << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
}
