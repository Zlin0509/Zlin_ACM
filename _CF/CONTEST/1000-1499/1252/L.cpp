//
// Created by 27682 on 2025/6/23.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

constexpr int MAXN = 250;
constexpr int INF = 0x3f3f3f3f;

struct EK {
    struct Edge {
        int from, to, cap, flow, cost;

        Edge(int u, int v, int c, int f, int co) : from(u), to(v), cap(c), flow(f), cost(co) {
        }
    };

    int n, m; // n：点数，m：边数
    vector<Edge> edges; // edges：所有边的集合
    vector<int> G[MAXN]; // G：点 x -> x 的所有边在 edges 中的下标
    int dis[MAXN], a[MAXN], p[MAXN]; // dis: 计算最短路径的数组
    bool inQueue[MAXN]; // 记录是否在队列中

    void init(int n) {
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }

    // 添加边 (from -> to, capacity, cost)
    void AddEdge(int from, int to, int cap, int cost) {
        edges.push_back(Edge(from, to, cap, 0, cost));
        edges.push_back(Edge(to, from, 0, 0, -cost)); // 反向边，费用取反
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    // 使用 SPFA (Shortest Path Faster Algorithm) 找增广路径
    bool SPFA(int s, int t) {
        fill(dis, dis + n, INF);
        memset(inQueue, 0, sizeof(inQueue));
        queue<int> Q;
        Q.push(s);
        dis[s] = 0;
        a[s] = INF;
        inQueue[s] = true;
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            inQueue[u] = false;
            for (int i: G[u]) {
                Edge &e = edges[i];
                if (e.cap > e.flow && dis[e.to] > dis[u] + e.cost) {
                    dis[e.to] = dis[u] + e.cost;
                    a[e.to] = min(a[u], e.cap - e.flow);
                    p[e.to] = i;
                    if (!inQueue[e.to]) {
                        Q.push(e.to);
                        inQueue[e.to] = true;
                    }
                }
            }
        }
        return dis[t] != INF;
    }

    // 最大费用流计算
    int MaxFlow(int s, int t) {
        int flow = 0, cost = 0;
        while (SPFA(s, t)) {
            int f = a[t]; // 增广流量
            flow += f;
            cost += f * dis[t]; // 计算费用
            // 更新流量和反向流量
            for (int u = t; u != s; u = edges[p[u]].from) {
                edges[p[u]].flow += f;
                edges[p[u] ^ 1].flow -= f; // 反向边流量减去
            }
        }
        return cost; // 返回最大费用
    }
};

inline void Zlin() {
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
