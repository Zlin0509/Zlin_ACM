//
// Created by Zlin on 2024/10/13.
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

struct node {
    ll w, val;

    bool operator<(const node &x) const {
        if (val * x.w != x.val * w)
            return val * x.w > x.val * w;
        return val < x.val;
    }
};

inline void Zlin() {
    int n, w, k;
    cin >> n >> w >> k;
    vector<node> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].w >> a[i].val;
    sort(a.begin() + 1, a.end());
    vll vis[n + 1], dp(n + 1), cost(n + 1);
    for (int i = 1; i <= n; i++) {
        int tag = 0;
        for (int j = 0; j < i; j++) {
            if (cost[j] + a[i].w > w) continue;
            if (dp[j] + a[i].val > dp[i]) {
                cost[i] = cost[j] + a[i].w;
                tag = j;
                dp[i] = dp[j] + a[i].val;
            } else if (dp[j] + a[i].val == dp[i] && vis[tag].size() < vis[j].size()) {
                cost[i] = cost[j] + a[i].w;
                tag = j;
            } else if (dp[j] + a[i].val == dp[i] && vis[tag].size() == vis[j].size()) {
                if (cost[j] + a[i].w < cost[i]) {
                    cost[i] = cost[j] + a[i].w;
                    tag = j;
                }
            }
        }
        vis[i] = vis[tag];
        vis[i].push_back(i);
    }
    ll ans = 0, check;
    for (int i = 1; i <= n; i++) {
        vll used(n + 1), b;
        for (auto it: vis[i]) used[it]++;
        for (int j = 1; j <= n; j++) if (!used[j]) b.push_back(a[j].val);
        if (b.empty()) continue;
        sort(b.begin(), b.end(), greater<ll>());
        check = dp[i];
        for (int j = 0; j < min(k, (int) b.size()); j++) check += b[j];
        ans = max(ans, check);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
}