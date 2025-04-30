//
// Created by Zlin on 2024/10/4.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 3e5 + 5;

int n;
ll k, ans;
vector<ll> a(N), pre(N), sub(N);
ll f[N][33];

inline void st() {
    for (int i = 1; i <= n; i++) f[i][0] = a[i] + k;
    int t = log(n) / log(2) + 1;
    for (int j = 1; j < t; j++)
        for (int i = 1; i <= n - (1 << j) + 1; i++)
            f[i][j] = gcd(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

inline ll query(int l, int r) {
    int k = log(r - l + 1) / log(2);
    return gcd(f[l][k], f[r - (1 << k) + 1][k]);
}

inline void Zlin() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    pre[1] = a[1];
    vi lx;
    lx.push_back(1);
    for (int i = 2; i <= n; i++) {
        pre[i] = gcd(a[i], pre[i - 1]);
        if (pre[i] < pre[i - 1]) lx.push_back(i);
    }
    sub[n] = a[n];
    for (int i = n - 1; i >= 1; i--) sub[i] = gcd(a[i], sub[i + 1]);
    ans = pre[n];
    st();
    for (int r = n; r >= 1; r--) {
        ll c;
        for (auto l: lx) {
            if (l > r) break;
            c = query(l, r);
            if (l != 1) c = gcd(c, pre[l - 1]);
            if (r != n) c = gcd(c, sub[r + 1]);
            ans = max(ans, c);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}