//
// Created by 27682 on 2025/4/15.
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

int n;
int st[N][22], a[N];
vi idx[N];
ll m, ans, cnt[N];

inline void init() {
    for (int i = 1; i <= n; i++)
        st[i][0] = a[i];
    int k = log(n) / log(2) + 1;
    for (int j = 1; j < k; j++) {
        for (int i = 1; i <= n - (1 << (j - 1)) + 1; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

inline int query(int l, int r) {
    int k = log(r - l + 1) / log(2);
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

void dfs(int l, int r, int top) {
    int but = query(l, r);
    cnt[r - l + 1] += top - but;
    auto it = lower_bound(idx[but].begin(), idx[but].end(), l);
    while (it != idx[but].end() && *it <= r) {
        if (l < *it) dfs(l, *it - 1, but);
        l = *it + 1;
        ++it;
    }
    if (l <= r) dfs(l, r, but);
}

inline void Zlin() {
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cnt[i] = 0;
        idx[i].clear();
        for (int j = 0; j < 22; j++)
            st[i][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        idx[a[i]].push_back(i);
    }
    init();
    cin >> m;
    dfs(1, n, n);
    ans = 0;
    for (int i = n; i && m; i--) {
        if (!cnt[i]) continue;
        ll k = m / i;
        k = min(k, cnt[i]);
        ans += (i - 1) * k;
        m -= k * i;
        cnt[i] -= k;
        if (cnt[i] && m) {
            ans += m - 1;
            m = 0;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
