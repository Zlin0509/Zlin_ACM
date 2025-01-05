//
// Created by Zlin on 2024/9/18.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const ll N = 5e5 + 5, inf = 4e18;
int n;
ll ans;
ll a[N], dep[N];
vi e[N];
vll b(N);

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], e[i].clear();
    for (int i = 2, x; i <= n; i++) {
        cin >> x;
        e[x].push_back(i);
        dep[i] = dep[x] + 1;
    }
    for (int i = 1; i <= n; i++) {
        if (e[i].empty()) {
            b[i] = inf;
        } else {
            b[i] = -a[i];
            for (auto v: e[i])
                b[i] += a[v];
        }
    }
    ans = 0;
    for (int i = n; i; i--) {
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int j: e[u]) {
                ll dif = min(-b[i], b[j]);
                if (dif > 0) {
                    b[i] += dif;
                    b[j] -= dif;
                    ans += dif * (dep[j] - dep[i]);
                }
                q.push(j);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}