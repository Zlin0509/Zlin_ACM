//
// Created by 27682 on 2025/6/26.
//
#include <bits/stdc++.h>
// #define endl '\n'
using namespace std;

constexpr int INF = 0x3f3f3f3f;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;

int sti(string c) {
    return (c[0] - 'a') * 8 + (c[1] - '1');
}

string its(int idx) {
    string c;
    c.push_back(idx / 8 + 'a');
    c.push_back(idx % 8 + '1');
    return c;
}

int i_tag(int i) {
    int x = i / 8, y = i % 8;
    return x + y * 8;
}

int dx[8]{-1, -1, -2, -2, 1, 1, 2, 2}, dy[8]{2, -2, 1, -1, 2, -2, 1, -1};

string cc[110];

int nxt[110], val[110];

vector<pii> ans, tmp;

struct MF {
    static const int N = 1000;

    struct edge {
        int to, nxt, cap, flow;
    } e[N * 3];

    int fir[N], cur[N], cnt = 0;

    int n, s, t;
    ll maxflow = 0;
    int dep[N], pre[N];

    void init(int N, int S, int T) {
        n = N, s = S, t = T;
        memset(fir, -1, sizeof(fir));
        cnt = 0;
    }

    void addEdge(int u, int v, int w) {
        e[cnt] = {v, fir[u], w, 0};
        fir[u] = cnt++;
        e[cnt] = {u, fir[v], 0, 0};
        fir[v] = cnt++;
    }

    bool bfs() {
        queue<int> q;
        memset(dep, 0, sizeof(int) * (n + 1));
        dep[s] = 1;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = fir[u]; ~i; i = e[i].nxt) {
                int v = e[i].to;
                if (!dep[v] && e[i].cap > e[i].flow) {
                    dep[v] = dep[u] + 1;
                    q.push(v);
                }
            }
        }
        return dep[t];
    }

    vi path;

    int dfs(int u, int flow) {
        if (u == t) {
            if (!val[path.back()]) {
                for (int i = path.size() - 2; i > 0; i--) {
                    tmp.push_back({path[i], path[i + 1]});
                    if (val[path[i]]) {
                        int lx = tmp[0].second, rx = tmp.back().first;
                        val[rx] = 0, val[lx] = 1;
                        while (!tmp.empty()) {
                            ans.push_back(tmp.back());
                            tmp.pop_back();
                        }
                    }
                }
                if (!tmp.empty()) {
                    int lx = tmp[0].second, rx = tmp.back().first;
                    val[rx] = 0, val[lx] = 1;
                    while (!tmp.empty()) {
                        ans.push_back(tmp.back());
                        tmp.pop_back();
                    }
                }
            }
        }
        if (u == t || !flow) return flow;
        int ret = 0;
        path.push_back(u);
        for (int &i = cur[u]; ~i; i = e[i].nxt) {
            int v = e[i].to, d;
            if (dep[v] == dep[u] + 1 && (d = dfs(v, min(flow - ret, e[i].cap - e[i].flow)))) {
                pre[v] = u;
                ret += d;
                e[i].flow += d;
                e[i ^ 1].flow -= d;
                if (ret == flow) break;
            }
        }
        path.pop_back();
        return ret;
    }

    void dinic() {
        while (bfs()) {
            memcpy(cur, fir, sizeof(int) * (n + 1));
            maxflow += dfs(s, INF);
        }
    }
} mf;

inline void Zlin() {
    int n, s = 69, t = 70;
    cin >> n;
    mf.init(70, s, t);
    for (int i = 0; i < n; i++) {
        cin >> cc[i];
        mf.addEdge(s, sti(cc[i]), 1);
        val[sti(cc[i])] = 1;
    }
    for (char i = 'a'; i <= 'h'; i++) {
        for (char j = '1'; j <= '8'; j++) {
            string c = string(1, i) + j;
            for (int k = 0; k < 8; k++) {
                char x = i + dx[k], y = j + dy[k];
                if (x < 'a' || x > 'h' || y < '1' || y > '8') continue;
                string cx = string(1, x) + y;
                mf.addEdge(sti(c), sti(cx), INF);
            }
        }
    }
    for (int i = 0; i < n; i++) mf.addEdge(i_tag(i), t, 1);
    mf.dinic();
    cout << ans.size() << endl;
    for (auto [u, v]: ans) cout << its(u) << '-' << its(v) << endl;
    // for (int i = 1; i <= 100; i++) val[i] = 0;
    // for (int i = 0; i < n; i++) val[sti(cc[i])] = 1;
    // for (auto [u, v]: ans) {
    //     val[v] = val[u], val[u] = 0;
    // }
    // for (int i = 0; i < n; i++) cout << val[i_tag(i)] << ' ';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
