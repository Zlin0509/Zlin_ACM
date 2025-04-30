#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int maxn = 100010;
int n, m, op, x, y;
int lc[maxn], rc[maxn], dist[maxn], rt[maxn];
bool tf[maxn];

struct node {
    int id, v;

    bool operator<(node x) const { return v == x.v ? id < x.id : v < x.v; }
} v[maxn];

int find(int x) { return rt[x] == x ? x : rt[x] = find(rt[x]); }

int merge(int x, int y) {
    if (!x || !y)return x + y;
    if (v[y] < v[x])swap(x, y);
    rc[x] = merge(rc[x], y);
    if (dist[lc[x]] < dist[rc[x]])swap(lc[x], rc[x]);
    dist[x] = dist[rc[x]] + 1;
    return x;
}

int main() {
    dist[0] = -1;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)scanf("%d", &v[i].v), rt[i] = i, v[i].id = i;
    while (m--) {
        scanf("%d%d", &op, &x);
        if (op == 1) {
            scanf("%d", &y);
            if (tf[x] || tf[y])continue;
            x = find(x);
            y = find(y);
            if (x != y)rt[x] = rt[y] = merge(x, y);
        }
        if (op == 2) {
            if (tf[x]) {
                printf("-1\n");
                continue;
            }
            x = find(x);
            printf("%d\n", v[x].v);
            tf[x] = true;
            rt[lc[x]] = rt[rc[x]] = rt[x] = merge(lc[x], rc[x]);
            lc[x] = rc[x] = dist[x] = 0;
        }
    }
    return 0;
}