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

const int N = 2e5 + 5;

struct edge {
    int to, nxt;
} e[N << 1];
int head[N], tot;

inline void add(int u, int v) {
    e[++tot] = {v, head[u]};
    head[u] = tot;
}

int n, c[N], cnt[N];
ll ans;

inline void dfs(int u, int fa) {
    int now = cnt[c[u]];
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v == fa) continue;
        cnt[c[u]] = 1;
        dfs(v, u);
    }
    ans += now;
    cnt[c[u]] = now + 1;
}

inline void Zlin() {
    cin >> n;
    ans = tot = 0;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        cnt[i] = head[i] = 0;
    }
    for (int i = 2, u, v; i <= n; i++) {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dfs(1, 0);
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