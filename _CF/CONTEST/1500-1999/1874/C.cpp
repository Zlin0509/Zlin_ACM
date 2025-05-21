//
// Created by 27682 on 2025/5/21.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m, in[5010];
vi e[5010];
vector<db> have[5010];
db res[5010], fac[5010][5010];

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        res[i] = in[i] = 0;
        e[i].clear();
        have[i].clear();
    }
    for (int i = 1, a, b; i <= m; i++) {
        cin >> a >> b;
        ++in[a];
        e[b].push_back(a);
    }
    res[n] = 1;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (have[u].size()) {
            sort(have[u].begin(), have[u].end(), greater<db>());
            for (int i = 0; i < have[u].size(); i++) res[u] += fac[have[u].size()][i + 1] * have[u][i];
        }
        for (int v: e[u]) {
            have[v].push_back(res[u]);
            if (!--in[v]) q.push(v);
        }
    }
    cout << setprecision(12) << fixed << res[1] << endl;
}

inline void dd() {
    for (int i = 1; i <= 5000; i++) {
        if (i & 1) {
            for (int j = 1; j <= i; j++) {
                fac[i][j] = 1.0 / i;
            }
        } else {
            fac[i][1] = 1.0 / i;
            for (int j = 2; j <= i; j++) {
                int r = j - 2, l = i - 2 - r;
                fac[i][j] = fac[i - 2][j - 1] * l + fac[i - 2][j - 2] * r;
                fac[i][j] /= i;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    dd();
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
