//
// Created by 27682 on 2025/3/26.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 2e5 + 5;

int n, m;
vi e[N];

int dfn[N], low[N], tot;
int stk[N], instk[N], top;
int scc[N], cnt;
bool cut[N];

void init() {
    tot = top = cnt = 0;
    for (int i = 1; i <= n; i++) {
        e[i].clear();
        dfn[i] = low[i] = 0;
        stk[i] = instk[i] = 0;
        scc[i] = 0;
        cut[i] = false;
    }
}

void tarjan(int x) {
    int ss = 0;
    dfn[x] = low[x] = ++tot;
    stk[++top] = x, instk[x] = 1;
    for (int y: e[x]) {
        if (!dfn[y]) {
            ++ss;
            tarjan(y);
            low[x] = min(low[x], low[y]);
            if (low[y] >= dfn[x]) cut[x] = true;
        } else if (instk[y]) low[x] = min(low[x], dfn[y]);
    }
    if (dfn[x] == low[x]) {
        int y;
        ++cnt;
        do {
            y = stk[top--];
            instk[y] = 0;
            scc[y] = cnt;
        } while (y != x);
    }
    if (ss == 1 && x == 1) cut[x] = false;
}

inline void Zlin() {
    cin >> n >> m;
    init();
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
