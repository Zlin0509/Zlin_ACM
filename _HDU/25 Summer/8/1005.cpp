//
// Created by Zlin on 2025/8/11.
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

constexpr int N = 5e5 + 10;

int n, w, idx[N], tot, num, fa[N];
int lx, tag;
vi rx;
ll val[N], mx[N], dep[N];
ll sum;

inline int find(int u) { return fa[u] == u ? u : fa[u] = find(fa[u]); }

inline void Zlin() {
    cin >> n >> w;
    tag = lx = 1, rx.clear(), rx.emplace_back(1e9);
    tot = num = 2, sum = w;
    val[1] = 0, val[2] = w;
    fa[1] = 1, fa[2] = 2;
    dep[1] = 0, dep[2] = 0;
    mx[1] = 0, mx[2] = 0;
    idx[1] = 1, idx[2] = 2;
    while (n--) {
        int op;
        cin >> op;
        if (op == 1) {
            cin >> w;
            idx[++tot] = ++num;
            fa[tot] = tot;
            dep[tot] = 0;
            mx[num] = 0;
            sum += w;
            val[num] = sum;
            rx.clear(), rx.emplace_back(1e9);
            while (tag + 1 <= num && val[tag + 1] <= sum - val[tag + 1]) {
                ++tag;
                if (mx[tag] == val[tag]) lx = max(lx, tag);
                if (mx[tag] == sum - val[tag]) rx.emplace_back(tag);
            }
        } else if (op == 2) {
            int x;
            cin >> x >> w;
            fa[++tot] = fa[x];
            dep[tot] = dep[x] + w;
            int f = idx[find(tot)];
            mx[f] = max(mx[f], dep[tot]);
            if (mx[f] == val[f]) lx = max(lx, f);
            if (mx[f] == sum - val[f]) rx.emplace_back(f);
        } else {
            sort(rx.begin(), rx.end());
            if (lx >= rx[0]) {
                cout << 0 << endl;
            } else {
                cout << val[min(num, rx[0])] - val[lx] << endl;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
