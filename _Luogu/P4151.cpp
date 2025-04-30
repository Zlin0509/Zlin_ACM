#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
#define LL long long
LL num[70];

bool insert(LL x) {
    for (int i = 63; i >= 0; i--)
        if ((x >> i) & 1) {
            if (!num[i]) {
                num[i] = x;
                return true;
            }
            x ^= num[i];
        }
    return false;
}

LL query(LL x) {
    LL res = x;
    for (int i = 63; i >= 0; i--)
        if ((res ^ num[i]) > res)
            res ^= num[i];
    return res;
}

struct edge {
    int to, next;
    LL w;
} e[200010];
int head[50010], ecnt;

inline void adde(int from, int to, LL w) {
    e[++ecnt] = (edge) {to, head[from], w}, head[from] = ecnt;
    e[++ecnt] = (edge) {from, head[to], w}, head[to] = ecnt;
}

int vis[50010];
LL del[50010];

void dfs(int u, LL res) {
    del[u] = res, vis[u] = 1;
    for (int i = head[u]; i; i = e[i].next)
        if (!vis[e[i].to]) dfs(e[i].to, res ^ e[i].w);
        else insert(res ^ e[i].w ^ del[e[i].to]);
}

int main() {
    int n, m, a, b;
    LL c;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) scanf("%d%d%lld", &a, &b, &c), adde(a, b, c);
    dfs(1, 0);
    printf("%lld\n", query(del[n]));
}