//
// Created by 27682 on 2025/4/18.
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

constexpr int N = 1505;

vi e[N];
int n, m, dis[N];

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        dis[i] = 1e9;
        e[i].clear();
    }
    for (int i = 1, a, b; i <= m; i++) {
        cin >> a >> b;
        e[b].push_back(a);
    }
    dis[1] = 1;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: e[u]) {
            if (dis[v] >= dis[u] + 1) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dis[i] == 1e9) {
            cout << "INFINITE" << endl;
            return;
        }
        ans += dis[i];
    }
    cout << "FINITE" << endl << ans << endl;
    vector<vi> have(n + 1);
    int maxn = 0;
    for (int i = 1; i <= n; i++) have[dis[i]].push_back(i), maxn = max(maxn, dis[i]);
    for (int i = maxn; i; i--)
        for (int j = i; j <= maxn; j++)
            for (auto k: have[j])
                cout << k << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
