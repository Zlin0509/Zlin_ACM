//
// Created by 27682 on 2025/9/27.
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

constexpr int N = 1e6 + 5;
constexpr int INF = 1e9;

int n, m, q, c[2];
int a[N << 1], cnt[N << 1];
vi e[N << 1];

inline void Zlin() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n + m + 1; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        e[i].emplace_back(i + 1);
        e[i + 1].emplace_back(i);
    }
    e[1].emplace_back(n + 2);
    e[n + 2].emplace_back(1);
    for (int i = n + 2; i < n + m + 1; i++) {
        e[i].emplace_back(i + 1);
        e[i + 1].emplace_back(i);
    }
    set<pii> st;
    for (int i = 1; i <= n + m + 1; i++) {
        if (a[i] < 0) {
            for (int v: e[i]) {
                if (a[i] + a[v] < 0) {
                    st.insert({min(i, v), max(i, v)});
                }
            }
        }
    }
    for (auto [x, y]: st) {
        cnt[x]++, cnt[y]++;
        if (x <= n + 1) c[0]++;
        else c[1]++;
        if (y <= n + 1) c[0]++;
        else c[1]++;
    }
    while (q--) {
        int s, t;
        cin >> s >> t;
        if (s == t) {
            cout << 0 << endl;
            continue;
        }
        if (t == 1) {
            if (s <= n + 1) {

            }
        } else {
            if (st.size() - cnt[t]) cout << 0 << endl;
            else {
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
