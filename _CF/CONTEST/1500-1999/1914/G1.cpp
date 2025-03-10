//
// Created by Zlin on 2024/10/30.
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

const int mo = 998244353;
const int N = 1010;

struct edge {
    int to, nxt;
} e[1000010];
int head[N], tot;

inline void add(int u, int v) {
    e[++tot] = {v, head[u]};
    head[u] = tot;
}

int dfn[N], low[N], now;
int stk[N], instk[N], top;
int n, a[N << 1], cnt[N], used[N][N];
ll ans;

int f[N];

inline int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }

inline void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    f[fx] = fy;
}

inline void tarjan(int x) {
    dfn[x] = low[x] = ++now;
    stk[++top] = x;
    instk[x] = 1;
    for (int i = head[x]; i; i = e[i].nxt) {
        int y = e[i].to;
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (instk[y]) {
            low[x] = min(low[x], dfn[y]);
        }
    }
    if (dfn[x] == low[x]) {
        int y, sum = 0;
        do {
            y = stk[top--];
            instk[y] = 0;
            sum += cnt[y];
        } while (y != x);
        if (low[x] == low[find(x)])
            ans = ans * sum % mo;
    }
}

void init() {
    ans = 1, tot = now = top = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
        cnt[i] = dfn[i] = low[i] = instk[i] = head[i] = 0;
        for (int j = 1; j <= n; j++) used[i][j] = 0;
    }
}

inline void Zlin() {
    cin >> n;
    init();
    for (int i = 1; i <= n * 2; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 1; i < n * 2; i++) {
        bool check = false;
        for (int j = n * 2; j > i; j--) {
            if (a[i] == a[j]) check = true;
            if (check && a[i] != a[j] && !used[a[i]][a[j]]) {
                add(a[i], a[j]);
                used[a[i]][a[j]] = 1;
                merge(a[j], a[i]);
            }
        }
    }
    int ans1 = 0;
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(find(i)), ++ans1;
    cout << ans1 << ' ' << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}