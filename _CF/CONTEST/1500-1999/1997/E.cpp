#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;
const int MAXM = 5e2 + 10;

int B = 3e3, V, a[MAXN], sum[MAXN][MAXM];

inline
void init(int n) {
    V = n / B + 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= V && j <= a[i]; j++) sum[i][j]++;
        for (int j = 1; j <= V; j++) sum[i][j] += sum[i - 1][j];
    }
}

inline
int ask(int ql, int qr, int x) {
    return sum[qr][x] - sum[ql - 1][x];
}

int n, m; bitset<MAXN> vis[3010];

inline
bool solve(int p, int x) {
    for (int i = 1, j = 1; i <= n; i++, j++) {
        int l = i, r = n, mid;
        for (; l < r; ask(i, mid = l + r >> 1, j) < x ? l = mid + 1 : r = mid);
        if (i <= p && p <= l) return a[p] >= j; i = l;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    init(n);
    for (int j = 1, k, x; j <= B; j++) {
        k = 1, x = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] < k) continue; vis[j][i] = 1;
            if (++x == j) ++k, x = 0;
        }
    }
    for (int p, x; m--;) {
        scanf("%d%d", &p, &x);
        if (x <= B) puts(vis[x][p] ? "YES" : "NO");
        else puts(solve(p, x) ? "YES" : "NO");
    }
}