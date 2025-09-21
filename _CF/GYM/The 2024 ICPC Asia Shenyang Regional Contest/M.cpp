//
// Created by 27682 on 2025/9/21.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 5e5;
constexpr ll inf = 1e18;

vi e[N], E[N];
int in[N], out[N];

int dfn[N], low[N], cnt;
int stk[N], instk[N], top;
int scc[N], num;
pll a[N];

int n, m;

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

inline void Zlin() {
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
