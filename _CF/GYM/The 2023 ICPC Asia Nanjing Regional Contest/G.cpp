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

const int N = 5e3 + 20, M = 1e4 + 10;

ll dp[N][M]{}, fin[N];

struct node {
    int w, v;

    bool operator<(const node &x) const {
        return w > x.w;
    }
} a[N];

inline void Zlin() {
    int n, w, k;
    cin >> n >> w >> k;
    for (int i = 1; i <= n; i++) cin >> a[i].w >> a[i].v;
    sort(a + 1, a + 1 + n);
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= w; j++) {
            dp[i][j] = dp[i + 1][j];
            if (j >= a[i].w) dp[i][j] = max(dp[i][j], dp[i + 1][j - a[i].w] + a[i].v);
            fin[i] = max(fin[i], dp[i][j]);
        }
    }
    ll sum = 0, ans = 0;
    priority_queue<int, vi, greater<int>> p;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, fin[i] + sum);
        sum += a[i].v;
        p.push(a[i].v);
        while (p.size() > k) {
            sum -= p.top();
            p.pop();
        }
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