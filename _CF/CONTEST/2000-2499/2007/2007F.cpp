//
// Created by Zlin on 2024/9/19.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 4e5 + 5;
int n, f[N][33], cnt[N];
ll ans;
struct node {
    ll a, cnt;
};
vector<node> a;

inline void st() {
    for (int i = 1; i < n; i++) {
        f[i][0] = abs(a[i + 1].a - a[i].a);
        while (f[i][0] % 2 == 0) f[i][0] >>= 1;
    }
    int t = log(n - 1) / log(2) + 1;
    for (int j = 1; j < t; j++)
        for (int i = 1; i <= n - 1 - (1 << j) + 1; i++)
            f[i][j] = gcd(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

inline int query(int l, int r) {
    int k = log(r - l + 1) / log(2);
    return gcd(f[l][k], f[r - (1 << k) + 1][k]);
}

inline void Zlin() {
    memset(cnt, 0, sizeof cnt);
    a.clear();
    ans = 0;
    cin >> n;
    a.push_back({0, 1});
    for (int i = 1, c; i <= n; i++) {
        cin >> c;
        if (c != a.back().a) {
            ans += a.back().cnt * (a.back().cnt - 1) / 2ll;
            a.push_back({c, 1});
        } else a.back().cnt++;
    }
    ans += a.back().cnt * (a.back().cnt - 1) / 2ll;
    ans += n;
    n = a.size() - 1;
    st();
    for (int i = n; i >= 1; i--) cnt[i] = cnt[i + 1] + a[i].cnt;
    for (int i = 1, l, r, mid; i < n; i++) {
        l = i, r = n;
        while (l < r) {
            mid = l + r >> 1;
            if (mid > i && query(i, mid - 1) == 1) r = mid;
            else l = mid + 1;
        }
        if (r > i && query(i, r - 1) == 1) ans += cnt[r] * a[i].cnt;
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