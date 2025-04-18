//
// Created by Zlin on 2025/1/16.
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

vi e[100010];
int n, dep[100010], in[100010];

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int v;
            cin >> v;
            e[i].push_back(v);
            ++in[v];
        }
    }
    queue<int> now;
    for (int i = 1; i <= n; i++) if (!in[i]) now.push(i);
    int ans = 0;
    while (!now.empty()) {
        int u = now.front();
        now.pop();
        for (int v: e[u]) {
            dep[v] = dep[u] + 1;
            ans = max(ans, dep[v]);
            now.push(v);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dep[i] == ans) {
            cout << i;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
