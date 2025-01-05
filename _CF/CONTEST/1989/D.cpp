//
// Created by Zlin on 2024/9/3.
//

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;

int n, m;
struct ss {
    int a, b;
} t[1000010];
int c[1000010]{}, dp[1000010]{};

bool cmp(const ss &a, const ss &b) {
    if (a.a - a.b != b.a - b.b) return a.a - a.b < b.a - b.b;
    return a.a < b.a;
}

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> t[i].a;
    for (int i = 1; i <= n; i++) cin >> t[i].b;
    for (int i = 1; i <= m; i++) cin >> c[i];
    sort(t + 1, t + 1 + n, cmp);
    vector<ss> to;
    int s = 1e7, dif;
    for (int i = 1; i <= n; i++)if (t[i].a < s) to.push_back(t[i]), s = t[i].a;
    s = to.size();
    ll ans = 0;
    for (int i = to[s - 1].a; i <= 1000000; i++) {
        if (s >= 1 && i == to[s - 1].a) {
            --s;
            dif = to[s].a - to[s].b;
        }
        dp[i] = max(dp[i - 1], dp[i - dif] + 1);
    }
    dif = to[0].a - to[0].b, s = to[0].a;
    for (int i = 1, k; i <= m; i++) {
        if (c[i] >= s) {
            k = (c[i] - s) / dif + 1;
            c[i] -= k * dif;
            ans += k;
        }
        ans += dp[c[i]];
    }
    cout << ans * 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    Zlin();
}