//
// Created by Zlin on 2024/9/30.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1e6 + 10;
int n, k;
ll ans;
int b[N << 1];
int f[N << 1];
set<int> have;
vi dd[N], vis(N), all[N << 1];

inline int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }

inline void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    f[fx] = fy;
}

inline void init() {
    for (int i = 1; i < n * 2; i++) f[i] = i;
    ans = 0;
    have.clear();
}


inline void Zlin() {
    cin >> n >> k;
    init();
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        if (x == 1) ans += n;
        b[i - 1] = b[n + i - 1] = x;
    }

    for (int i = 1; i < n * 2; i++) {
        for (auto j: dd[b[i]]) {
            have.insert(j);
            all[j].push_back(i);
        }
    }

    for (auto x: have) {
        all[x].erase(unique(all[x].begin(), all[x].end()), all[x].end());
        int j = 0;
        for (auto i: all[x]) {
            if (j && i - j <= k)
                merge(i, j);
            j = i;
        }
        all[x].clear();
    }

    for (int i = 1; i < n * 2; i++) {
        if (b[i] != 1)
            ans += (find(i) == i);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;

    for (int i = 2; i < N; i++) {
        if (vis[i]) continue;
        for (int j = 1; j * i < N; j++) {
            vis[i * j] = i;
            dd[i * j].push_back(i);
        }
    }

    while (ttt--)
        Zlin();
}