//
// Created by Zlin on 2024/10/10.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const int N = 1e5 + 20;
const int M = 1e5 + 20;

int n, m;// n: 左侧顶点数, m: 右侧顶点数
vi mtl(N), mtr(N), dis(N);// mtl,mtr:左侧和右侧的匹配情况 dis:记录距离（用于 BFS）
vector<vi> gl(N), gr(N);// 存储二分图的邻接表

bool bfs() {
    queue<int> q;
    for (int u = 1; u <= n; u++) {
        if (mtl[u] == -1) {//初始化起点，如果没有被匹配过，距离为零，放入队列
            dis[u] = 0;
            q.push(u);
        } else {//如果有，则赋值为inf
            dis[u] = inf;
        }
    }
    bool check = false;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: gl[u]) {
            int vv = mtr[v];//表示右边能到达的点的匹配点
            if (vv == -1) {//如果为-1，说明这个右边的点没有被匹配，能直接使用
                check = true;
            } else if (dis[vv] == inf) {//如果不为-1，说明他和vv匹配，把vv放到队列中，同时更新dis[vv]，说明vv和u是间隔相邻
                dis[vv] = dis[u] + 1;
                q.push(vv);
            }
        }
    }
    return check;
}

bool dfs(int u) {
    for (int v: gl[u]) {
        int vv = mtr[v];
        if (vv == -1 || (dis[vv] == dis[u] + 1 && dfs(vv))) {
            mtl[u] = v;
            mtr[v] = u;
            return true;
        }
    }
    dis[u] = inf;//重置距离
    return false;
}

int HK() {
    for (int i = 1; i <= n; i++) mtl[i] = -1;
    for (int i = 1; i <= n; i++) mtr[i] = -1;
    int mt = 0;
    while (bfs()) // 分阶段寻找增广路径
        for (int u = 1; u <= n; u++)
            if (mtl[u] == -1 && dfs(u))// 如果没被匹配过同时找到增广路径，匹配数加1
                ++mt;
    return mt;
}

int cnt[2], vis[2][N];

void DFS_l(int u) {
    if (vis[0][u]) return;
    ++cnt[0];
    vis[0][u] = 1;
    for (int v: gl[u])
        if (mtr[v] != -1)
            DFS_l(mtr[v]);
}

void DFS_r(int u) {
    if (vis[1][u]) return;
    ++cnt[1];
    vis[1][u] = 1;
    for (int v: gr[u])
        if (mtl[v] != -1)
            DFS_r(mtl[v]);
}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        vis[0][i] = vis[1][i] = 0;
        gl[i].clear();
        gr[i].clear();
    }
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        gl[u].push_back(v);
        gr[v].push_back(u);
    }
    HK();
    cnt[0] = cnt[1] = 0;
    for (int i = 1; i <= n; i++) {
        if (mtl[i] == -1)
            DFS_l(i);
        if (mtr[i] == -1)
            DFS_r(i);
    }
    cout << 1ll * cnt[0] * cnt[1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
}