//
// Created by Zlin on 2024/10/8.
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
const int N = 1e6;

vi f(N * 2 + 5);
int cnt;

ll qpw(ll u, ll v) {
    ll res = 1;
    while (v) {
        if (v & 1) res = res * u % mo;
        u = u * u % mo;
        v >>= 1;
    }
    return res;
}

int find(int u) {
    return f[u] == u ? u : f[u] = find(f[u]);
}

void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (f[fx] == f[fy]) return;
    --cnt;
    f[fx] = fy;
}

inline void Zlin() {
    int r, c;
    cin >> r >> c;
    vi vis(c + 1);
    vector<vector<char>> a(r * 2 + 1, vector<char>(c + 1));
    vector<vector<int>> have(c + 1);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> a[i][j];
            a[i + r][c - j + 1] = a[i][j];
            if (a[i][j] == '1') {
                have[j].push_back(i);
                have[c - j + 1].push_back(i + r);
            }
        }
    }
    for (int i = 1; i <= c; i++) {
        if (have[i].size() > 2) {
            cout << 0 << '\n';
            return;
        }
    }
    cnt = r * 2;
    for (int i = 1; i <= cnt; i++) f[i] = i;
    for (int i = 1; i <= r * 2; i++) {
        for (int j = 1; j <= c; j++) {
            if (a[i][j] == '0') continue;
            for (auto k: have[c - j + 1]) {
                if (k == i + r || i == k + r) continue;
                merge(i, k);
            }
        }
    }
    for (int i = 1; i <= r; i++) {
        if (find(i) == find(i + r)) {
            cout << 0 << '\n';
            return;
        }
    }
    ll ans = qpw(2, cnt / 2);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
}