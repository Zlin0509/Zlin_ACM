//
// Created by 27682 on 2025/3/28.
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

constexpr int N = 1e5 + 10;
constexpr ll mo = 1e9 + 7;

int n, m, c;
ll a[N], f[N], cnt[N];
queue<int> e[N];

inline void Zlin() {
    cin >> n >> c;
    for (int i = 1; i <= c; i++) {
        f[i] = cnt[i] = 0;
        while (!e[i].empty()) e[i].pop();
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    cin >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[u].push(v);
        e[v].push(u);
    }
    f[a[1]] = 1;
    queue<int> q;
    for (int i = 1, tag; i < n; i++) {
        ll val = f[a[i]];
        --cnt[a[i]];
        while (!e[a[i]].empty()) {
            tag = e[a[i]].front();
            e[a[i]].pop();
            if (cnt[tag]) {
                f[tag] += val;
                q.push(tag);
            }
        }
        while (!q.empty()) {
            e[a[i]].push(q.front());
            q.pop();
        }
    }
    cout << f[a[n]] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
