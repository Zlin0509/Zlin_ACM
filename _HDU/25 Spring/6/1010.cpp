//
// Created by 27682 on 2025/4/11.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 2e5 + 10;

ll ans[N];
int n;
vi e[N];


inline ll dfs(int u, int fa) {
    vector<ll> have;
    ll cnt = 1, all;
    for (int v: e[u]) {
        if (v == fa) continue;
        ll now = dfs(v, u);
        cnt += now;
        have.push_back(now);
    }
    have.push_back({n - cnt});
    all = 0;
    for (ll val: have) all += (n - 1 - val) * val;
    all /= 2;
    ans[u] = all + n;
    for (ll val: have) ans[u] += val * (n - val + all - val * (n - 1 - val));
    return cnt;
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ans[i] = 0;
        e[i].clear();
    }
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (e[i].size() == 1) {
            dfs(i, 0);
            break;
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
