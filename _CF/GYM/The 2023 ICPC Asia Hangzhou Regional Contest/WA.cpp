//
// Created by Zlin on 2024/10/15.
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

const ll mo = 1e9 + 7;
const int N = 5e5 + 5;


ll d[N], inv[N];

inline ll quick_pow(ll a, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1)
            res = res * a % mo;
        a = a * a % mo;
        n >>= 1;
    }
    return res;
}

void dd() {
    d[1] = 1;
    for (ll i = 2; i < N; i++)
        d[i] = d[i - 1] * i % mo;
    inv[N - 1] = quick_pow(d[N - 1], mo - 2);
    for (ll i = N - 2; i >= 1; i--)
        inv[i] = inv[i + 1] * (i + 1) % mo;
}

vi e[N];
int n;
ll a[N], b[N], w[N], dep[N], tag[N], ans[N];

void dfs(int u) {
    for (auto v: e[u]) {
        dep[v] = dep[u] + 1;
        dfs(v);
    }
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        tag[i] = dep[i] = 0;
        e[i].clear();
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) {
        if (a[i] < a[b[i]]) tag[i] = 1;
        else if (a[i] >= a[b[i]] + w[b[i]]) tag[i] = -1;
        else e[b[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (tag[i] != 1) continue;
        dfs(i);
    }
    for (int i = 1; i <= n; i++) {
        if (tag[i] == 1) {
            ans[i] = a[i] + w[i];
        } else if (tag[i] == -1) {
            ans[i] = a[i];
        } else {
            if (dep[i]) {
                ans[i] = (w[i] * inv[dep[i] + 1] % mo + a[i]) % mo;
            } else {
                ans[i] = a[i];
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    dd();
//    cin >> ttt;
    while (ttt--) Zlin();
}