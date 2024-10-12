//
// Created by Zlin on 2024/10/12.
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

inline void Zlin() {
    int n, cnt = 0;
    cin >> n;
    vi d(n + 1, 0);
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        d[u]++, d[v]++;
    }
    for (int i = 1; i <= n; i++)
        if (d[i] >= 2)
            ++cnt;
    if (cnt == 0 || cnt & 1) cout << "Bob" << '\n';
    else cout << "Alice" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
}