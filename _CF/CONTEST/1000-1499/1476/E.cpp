//
// Created by 27682 on 2025/6/22.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
const int N = 4e5 + 10, INF = 0x3f3f3f3f3f3f3f3f, mod = 998244353;
int n, m, k, tot, in[N], ed[N], t[N][27];
char s[N];
vector<int> e[N], ans;

namespace Fast_IO {
    static char buf[1000000], *paa = buf, *pd = buf, out[10000000];
    int length = 0;
#define getchar() paa==pd&&(pd=(paa=buf)+fread(buf,1,1000000,stdin),paa==pd)?EOF:*paa++

    inline int read() {
        int x(0), t(1);
        char fc(getchar());
        while (!isdigit(fc)) {
            if (fc == '-') t = -1;
            fc = getchar();
        }
        while (isdigit(fc)) x = (x << 1) + (x << 3) + (fc ^ 48), fc = getchar();
        return x * t;
    }

    inline void flush() {
        fwrite(out, 1, length,stdout);
        length = 0;
    }

    inline void put(char c) {
        if (length == 9999999) flush();
        out[length++] = c;
    }

    inline void put(string s) { for (char c: s) put(c); }

    inline void print(int x) {
        if (x < 0) put('-'), x = -x;
        if (x > 9) print(x / 10);
        put(x % 10 + '0');
    }

    inline bool chk(char c) {
        return !(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9' || c == '_');
    }

    inline bool ck(char c) { return c != '\n' && c != '\r' && c != -1 && c != ' '; }

    inline void rd(char s[], int &n) {
        s[++n] = getchar();
        while (chk(s[n])) s[n] = getchar();
        while (ck(s[n])) s[++n] = getchar();
        n--;
    }
}

using namespace Fast_IO;

inline void insert(char s[], int n, int i) {
    int u = 0;
    for (int i = 1; i <= n; i++) {
        int v = (s[i] == '_') ? 26 : s[i] - 'a';
        if (!t[u][v]) t[u][v] = ++tot;
        u = t[u][v];
    }
    ed[u] = i;
}

inline bool dfs(int u, int dep, int x) {
    int f = 0;
    if (dep == k + 1) {
        if (ed[u] == x) return true;
        e[x].emplace_back(ed[u]);
        in[ed[u]]++;
    }
    if (t[u][s[dep] - 'a']) f |= dfs(t[u][s[dep] - 'a'], dep + 1, x);
    if (t[u][26]) f |= dfs(t[u][26], dep + 1, x);
    return f;
}

inline void toposort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) if (!in[i]) q.push(i);
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        ans.emplace_back(u);
        for (auto v: e[u]) if (!--in[v]) q.push(v);
    }
    if (ans.size() != n) return put("NO");
    put("YES\n");
    for (auto v: ans) print(v), put(' ');
}

signed main() {
    n = read(), m = read(), k = read();
    for (int i = 1, l; i <= n; i++) l = 0, rd(s, l), insert(s, l, i);
    for (int i = 1, l; i <= m; i++) {
        l = 0, rd(s, l);
        if (!dfs(0, 1, read())) {
            put("NO");
            goto genshin;
        }
    }
    toposort();
genshin:;
    flush();
    return 0;
}
