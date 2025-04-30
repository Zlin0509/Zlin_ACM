//
// Created by Zlin on 2024/9/13.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

vi e[10010]{}, c(10010), flag(10010), cc(10010);
int n, m;
bool check;

inline void dfs(int u, int fa) {
    cc[u] = cc[fa] ^ 1;
    for (auto v: e[u]) {
        if (v == fa) continue;
        if (cc[v] == -1) dfs(v, u);
        else {
            if (cc[v] == cc[u]) {
                check = true;
                return;
            }
        }
    }
}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        e[i].clear();
        cc[i] = -1;
    }
    check = false;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    cout << (check ? "Alice" : "Bob") << '\n';
    cout.flush();
    if (check) {
        for (int i = 1, x, y; i <= n; i++) {
            cout << "1 2" << '\n';
            cout.flush();
            cin >> x >> y;
        }
    } else {
        queue<int> l, r;
        for (int i = 1; i <= n; i++) cc[i] ? l.push(i) : r.push(i);
        for (int i = 1, a, b; i <= n; i++) {
            cin >> a >> b;
            if ((a == 1 | b == 1) && !l.empty()) {
                cout << l.front() << ' ' << 1 << '\n';
                l.pop();
            } else if ((a == 2 || b == 2) && !r.empty()) {
                cout << r.front() << ' ' << 2 << '\n';
                r.pop();
            } else if (!l.empty()) {
                cout << l.front() << ' ' << ((a == 1 || b == 1) ? 1 : 3) << '\n';
                l.pop();
            } else {
                cout << r.front() << ' ' << ((a == 2 || b == 2) ? 2 : 3) << '\n';
                r.pop();
            }
            cout.flush();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}