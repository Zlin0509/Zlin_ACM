//
// Created by Zlin on 2024/12/12.
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

int n, in[N], f[N], dep[N];
priority_queue<int> e[N];

struct node {
    int val, top;

    bool operator<(const node &x) const {
        if (val != x.val) return val > x.val;
        return top > x.top;
    }
};

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        while (!e[i].empty()) e[i].pop();
        in[i] = 0;
    }
    for (int i = 2, x; i <= n; i++) {
        cin >> x;
        in[x]++;
        f[i] = x;
    }

    queue<int> q;
    priority_queue<node> qq;
    for (int i = 1; i <= n; i++) if (!in[i]) q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        dep[u] = 0;

        if (!e[u].empty()) {
            qq.push({e[u].top() + 1, 1});
            e[u].pop();
        }
        if (!e[u].empty()) {
            qq.push({e[u].top() + 1, 1});
            e[u].pop();
        }

        while (!e[u].empty()) {
            node x = qq.top();
            qq.pop();
            x.val++, x.top++;
            qq.push({e[u].top() + x.top, x.top});
            qq.push(x);
            e[u].pop();
        }

        while (!qq.empty()) {
            dep[u] = max(dep[u], qq.top().val);
            qq.pop();
        }
        --in[f[u]];
        e[f[u]].push(dep[u]);
        if (!in[f[u]]) q.push(f[u]);
    }
    cout << dep[1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}