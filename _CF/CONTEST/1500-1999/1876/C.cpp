//
// Created by Zlin on 2024/11/1.
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
int n, in[N], c[N], a[N];
int fa[N];

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        fa[i] = a[i];
        in[a[i]]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) if (!in[i]) q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int v = fa[u];
        --in[v];
        if (!c[u]) c[v] = 1;
        if (!in[v]) q.push(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!in[i]) continue;
        int s = i;
        while (fa[s] != i) {
            if (c[s]) break;
            s = fa[s];
        }
        int u = s;
        while (fa[s] != u) {
            --in[s];
            if (!c[s]) c[fa[s]] = 1;
            s = fa[s];
        }
        --in[s];
        if (!c[s] && !c[u]) {
            cout << -1 << '\n';
            return;
        }
    }
    vi ans;
    for (int i = 1; i <= n; i++) if (!c[i]) ans.push_back(a[i]);
    cout << ans.size() << '\n';
    for (int i: ans) cout << i << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}