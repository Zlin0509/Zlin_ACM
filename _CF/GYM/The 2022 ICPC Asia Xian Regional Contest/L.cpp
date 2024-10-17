//
// Created by Zlin on 2024/10/17.
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

const int N = 1e6 + 5;
int n, fa[N], d[N], ans, cnt, k;

inline void Zlin() {
    cin >> n;
    for (int i = 2, x; i <= n; i++) {
        cin >> x;
        fa[i] = x;
        ++d[x], ++d[i];
    }
    queue<int> q;
    for (int i = 2; i <= n; i++) {
        if (d[i] == 1) q.push(i);
        --d[i];
    }
    ans = n;
    cnt = 0;
    while (!q.empty()) {
        k = q.size();
        ans = min(ans, k + cnt);
        ++cnt;
        while (k--) {
            int u = q.front();
            q.pop();
            if (!fa[u]) continue;
            --d[fa[u]];
            if (!d[fa[u]]) q.push(fa[u]);
        }
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) d[i] = fa[i] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}