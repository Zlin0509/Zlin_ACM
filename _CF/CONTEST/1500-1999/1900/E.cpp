//
// Created by Zlin on 2024/11/1.
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

const int N = 2e5 + 5;
const ll inf = 1e18;

vi e[N], E[N];
int in[N], out[N];

int dfn[N], low[N], cnt;
int stk[N], instk[N], top;
int scc[N], siz[N], num;

ll val[N], f2[N], ans2;
int n, m, a[N], f1[N], ans1;

void tarjan(int x) {
    dfn[x] = low[x] = ++cnt;
    stk[++top] = x, instk[x] = 1;
    for (int y: E[x]) {
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (instk[y]) {
            low[x] = min(low[x], dfn[y]);
        }
    }
    if (low[x] == dfn[x]) {
        int y;
        ++num;
        do {
            y = stk[top--];
            instk[y] = 0;
            scc[y] = num;
            val[num] += a[y];
            siz[num]++;
        } while (x != y);
    }
}

void build_new() {
    for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
    for (int x = 1; x <= n; x++)
        for (int y: E[x])
            if (scc[x] != scc[y])
                e[scc[x]].push_back(scc[y]);
    for (int i = 1; i <= num; i++) {
        sort(e[i].begin(), e[i].end());
        e[i].erase(unique(e[i].begin(), e[i].end()), e[i].end());
    }
    for (int x = 1; x <= num; x++)
        for (int y: e[x])
            ++out[x], ++in[y];
}

void init() {
    for (int i = 1; i <= n; i++) {
        E[i].clear();
        dfn[i] = low[i] = stk[i] = instk[i] = scc[i] = 0;
    }
    for (int i = 1; i <= num; i++) {
        val[i] = siz[i] = f1[i] = in[i] = out[i] = 0;
        f2[i] = inf;
        e[i].clear();
    }
    num = cnt = top = 0;
}

inline void Zlin() {
    cin >> n >> m;
    init();
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        if (x != y) E[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        sort(E[i].begin(), E[i].end());
        E[i].erase(unique(E[i].begin(), E[i].end()), E[i].end());
    }
    build_new();
    queue<int> q;
    for (int i = 1; i <= num; i++)
        if (!in[i]) {
            f1[i] = siz[i];
            f2[i] = val[i];
            q.push(i);
        }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: e[u]) {
            --in[v];
            if (f1[v] < f1[u] + siz[v]) {
                f1[v] = f1[u] + siz[v];
                f2[v] = f2[u] + val[v];
            } else if (f1[v] == f1[u] + siz[v]) {
                f2[v] = min(f2[v], f2[u] + val[v]);
            }
            if (!in[v]) q.push(v);
        }
    }
    ans1 = 0, ans2 = inf;
    for (int i = 1; i <= num; i++) ans1 = max(ans1, f1[i]);
    for (int i = 1; i <= num; i++) if (ans1 == f1[i]) ans2 = min(ans2, f2[i]);
    cout << ans1 << ' ' << ans2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}