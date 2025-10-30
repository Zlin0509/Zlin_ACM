//
// Created by 27682 on 2025/10/30.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 2e5 + 1;

int n, k, c[N];
vi e[N];
pii Edge[N];
int ans;

inline void dfs(int u, int fa, int col) {
    int now = -1;
    for (const int &id: e[u]) {
        if (Edge[id].first == fa || Edge[id].second == fa) continue;
        int v = Edge[id].first == u ? Edge[id].second : Edge[id].first;
        now = (now + 1) % ans;
        if (now == col) now = (now + 1) % ans;
        c[id] = now + 1;
        dfs(v, u, now);
    }
}

inline void Zlin() {
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        cin >> Edge[i].first >> Edge[i].second;
        e[Edge[i].first].push_back(i);
        e[Edge[i].second].push_back(i);
    }
    vi tmp;
    for (int i = 1; i <= n; i++) tmp.emplace_back(e[i].size());
    sort(tmp.begin(), tmp.end(), greater<int>());
    ans = tmp[k];
    dfs(1, 0, -1);
    cout << ans << endl;
    for (int i = 0; i < n - 1; i++) cout << c[i] << ' ';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
