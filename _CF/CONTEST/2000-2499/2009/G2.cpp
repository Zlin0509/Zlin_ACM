//
// Created by Zlin on 2024/10/23.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int N = 2e5 + 10;
constexpr int MAXN = 20;

int n, k, q;
ll nxt[N][MAXN], val[N][MAXN];
ll a[N], f[N];

inline void Zlin() {
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= i;
    }

    map<ll, ll> mp;
    multiset<ll> s;
    for (int i = 1; i <= k; i++) {
        if (mp[a[i]]) s.erase(s.find(mp[a[i]]));
        ++mp[a[i]];
        s.insert(mp[a[i]]);
    }
    for (int i = k + 1; i <= n; i++) {
        f[i - k] = k - *prev(s.end());
        s.erase(s.find(mp[a[i - k]]));
        --mp[a[i - k]];
        s.insert(mp[a[i - k]]);
        if (mp[a[i]]) s.erase(s.find(mp[a[i]]));
        ++mp[a[i]];
        s.insert(mp[a[i]]);
    }
    f[n + 1 - k] = k - *prev(s.end());

    // for (int i = 1; i <= n; i++)
    //     cout << f[i] << " ";
    // cout << endl;

    stack<pll> have;
    for (int i = n - k + 1; i; i--) {
        while (!have.empty() && have.top().second >= f[i]) have.pop();
        have.empty() ? nxt[i][0] = n - k + 2 : nxt[i][0] = have.top().first;
        val[i][0] = f[i] * (nxt[i][0] - i);
        have.push({i, f[i]});
    }
    for (int i = 0; i < MAXN; i++)
        nxt[n - k + 2][i] = n - k + 2;
    for (int j = 1; j < MAXN; j++) {
        for (int i = 1; i <= n - k + 1; i++) {
            nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
            val[i][j] = val[i][j - 1] + val[nxt[i][j - 1]][j - 1];
        }
    }

    while (q--) {
        ll l, r;
        cin >> l >> r;
        r = r - k + 1;
        ll ans = 0;
        for (int i = MAXN - 1; ~i; i--) {
            if (nxt[l][i] > r) continue;
            ans += val[l][i];
            l = nxt[l][i];
        }
        cout << ans + (r - l + 1) * f[l] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
