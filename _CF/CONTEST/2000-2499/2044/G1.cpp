//
// Created by Zlin on 2024/12/16.
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

vi e[N];
int n, vis[N], tag[N], in[N];
int dfn[N], low[N], tot;
int stk[N], instk[N], top;

inline void tarjan(int x) {
    dfn[x] = low[x] = ++tot;
    stk[++top] = x, instk[x] = 1;
    for (int y: e[x]) {
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (instk[y])
            low[x] = min(low[x], dfn[y]);
    }
    if (dfn[x] == low[x]) {
        int y;
        vi have;
        do {
            y = stk[top--];
            instk[y] = 0;
            have.push_back(y);
        } while (y != x);
        if (have.size() > 1) for (auto it: have)tag[it] = 1;
    }
}

int dep[N];

inline void topoSort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!in[i] && !tag[i]) {
            q.push(i);
            dep[i] = 1;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: e[u]) {
            if (tag[v]) continue;
            dep[v] = max(dep[v], dep[u] + 1);
            in[v]--;
            if (!in[v]) {
                q.push(v);
            }
        }
    }
}

inline void Zlin() {
    cin >> n;
    tot = top = 0;
    for (int i = 1; i <= n; i++) {
        vis[i] = dfn[i] = low[i] = dep[i] = tag[i] = in[i] = 0;
        e[i].clear();
    }
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        e[i].push_back(x);
        in[x]++;
    }
    for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
    // for (int i = 1; i <= n; i++) cout << tag[i] << ' ';
    topoSort();

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dep[i] + 2);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
