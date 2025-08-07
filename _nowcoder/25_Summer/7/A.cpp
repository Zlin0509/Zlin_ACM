//
// Created by Zlin on 2025/8/5.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int id, m, k, n;
int a[11][11];

inline void Zlin() {
    cin >> id >> m >> k >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= k; j++)
            for (int x = 1; x <= n; x++)
                for (int y = 1; y <= n; y++)
                    cin >> a[x][y];
    for (int i = 1; i <= m; i++) cout << rng() % 2;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}