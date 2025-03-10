//
// Created by Zlin on 2024/10/16.
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

const int N = 3e5;
int c[N + 10];
vi have, ans, e[2010];
int vis[2010][2010];

void dd() {
    for (int i = 2; i <= N; i++)
        for (int j = 1; j * i <= N; j++)
            c[i * j]++;
    for (int i = 2; i <= N && have.size() < 2000; i++)
        if (c[i] == 1)
            have.push_back(i);
}

void dfs(int u) {
    while (!e[u].empty()) {
        int v = e[u].back();
        e[u].pop_back();
        if (!vis[u][v]) continue;
        vis[u][v] = vis[v][u] = 0;
        dfs(v);
    }
    ans.push_back(u);
}

inline void Zlin() {
    int n;
    cin >> n;
    int l = 1, r = n, mid;
    while (l < r) {
        mid = l + r >> 1;
        if (mid & 1) {
            if (mid * (mid + 1) / 2 >= n - 1) r = mid;
            else l = mid + 1;
        } else {
            if (mid * mid / 2 + 1 >= n - 1) r = mid;
            else l = mid + 1;
        }
    }
    for (int i = 1; i <= l; i++)
        for (int j = 1; j <= l; j++) {
            e[i].push_back(j);
            vis[i][j] = 1;
        }
    dfs(1);
    for (int i = 0; i < n; i++) cout << have[ans[i]] << ' ';
    ans.clear();
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    dd();
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}