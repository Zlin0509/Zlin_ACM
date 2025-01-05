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

int f[2020]{}, a[2020]{}, vis[2020]{};
int cost[2020];
int n, cnt;

inline int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }

inline void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    f[fx] = fy;
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], f[i] = i;
    cnt = 0;
    vector<pii> ans(n);
    for (int i = n - 1; i; i--) {
        for (int j = 1; j <= n; j++) {
            if (cost[a[j] % i] && find(cost[a[j] % i]) != find(j)) {
                ++cnt;
                merge(cost[a[j] % i], j);
                ans[i] = {cost[a[j] % i], j};
                break;
            }
            cost[a[j] % i] = j;
        }
        for (int j = 0; j < n; j++) cost[j] = 0;
    }
    if (cnt == n - 1) {
        cout << "YES" << '\n';
        for (int i = 1; i < n; i++) cout << ans[i].first << ' ' << ans[i].second << '\n';
    } else cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}