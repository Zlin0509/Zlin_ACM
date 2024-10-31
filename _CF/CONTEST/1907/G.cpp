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

const int N = 1e5 + 5;

struct edge {
    int to, nxt;
} e[N << 1];
int head[N], tot;

inline void add(int u, int v) {
    e[++tot] = {v, head[u]};
    head[u] = tot;
}

int n, c[N], d[N], f[N];
string s;

int ans, tag, sum;

vi op, cc;

void init() {
    cc.clear();
    op.clear();
    tot = ans = 0;
    for (int i = 1; i <= n; i++) {
        head[i] = d[i] = 0;
        f[i] = i;
    }
}

void dfs(int u, int fa) {
    cc.push_back(u);
    d[u] = 0;
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v == fa || d[v] == 0) continue;
        dfs(v, u);
    }
}

inline void Zlin() {
    cin >> n;
    init();
    cin >> s;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        f[i] = x;
        if (f[x] != i) {
            ++d[i], ++d[x];
            add(i, x);
            add(x, i);
        }
        c[i] = s[i - 1] - '0';
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (d[i] == 1)
            q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        --d[u];
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].to;
            if (!d[v]) continue;
            if (c[u]) {
                c[v] ^= c[u];
                c[u] = 0;
                ++ans;
                op.push_back(f[u] == v ? u : v);
            }
            --d[v];
            if (d[v] == 1) q.push(v);
        }
    }
    for (int i = 1; i <= n; i++)
        if (d[i]) {
            dfs(i, 0);
            break;
        }
    if (cc.empty()) {
        for (int i = 1; i <= n; i++)
            if (c[i]) {
                cout << -1 << '\n';
                return;
            }
        cout << ans << '\n';
        for (int i: op) cout << i << ' ';
        cout << '\n';
        return;
    }
    tag = sum = 0;
    for (int i: cc) {
        if (tag) ++sum;
        tag ^= c[i];
    }
    if (tag) {
        cout << -1 << '\n';
        return;
    }
    tag = c[cc[0]];
    if (sum <= cc.size() - sum) {
        ans += sum;
        for (int i = 1; i < cc.size(); i++) {
            if (tag) op.push_back(f[cc[i]] == cc[i - 1] ? cc[i] : cc[i - 1]);
            tag ^= c[cc[i]];
        }
    } else {
        ans += cc.size() - sum;
        for (int i = 1; i < cc.size(); i++) {
            if (!tag) op.push_back(f[cc[i]] == cc[i - 1] ? cc[i] : cc[i - 1]);
            tag ^= c[cc[i]];
        }
        op.push_back(f[cc[0]] == cc.back() ? cc[0] : cc.back());
    }
    cout << ans << '\n';
    for (int i: op) cout << i << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}