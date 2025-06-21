//
// Created by 27682 on 2025/6/17.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 3e5 + 10;

int ans;
int n, dfn[N], tot, lx[N], rx[N];
vi e1[N], e2[N];
set<pii> st;

inline void dfs1(int u) {
    lx[u] = rx[u] = dfn[u] = ++tot;
    for (int v: e2[u]) {
        dfs1(v);
        rx[u] = max(rx[u], rx[v]);
    }
}

inline void dfs2(int u) {
    auto it = st.upper_bound({dfn[u], 0});
    if (it == st.begin() || prev(it)->second < dfn[u]) {
        st.insert({lx[u], rx[u]});
        ans = max(ans, (int) st.size());
        for (int v: e1[u]) dfs2(v);
        st.erase(st.find({lx[u], rx[u]}));
    } else {
        pii tmp = *prev(it);
        st.erase(prev(it));
        st.insert({lx[u], rx[u]});
        ans = max(ans, (int) st.size());
        for (int v: e1[u]) dfs2(v);
        st.erase(st.find({lx[u], rx[u]}));
        st.insert(tmp);
    }
}

inline void Zlin() {
    cin >> n;
    ans = tot = 0;
    for (int i = 1; i <= n; i++) {
        lx[i] = N, rx[i] = 0;
        e1[i].clear();
        e2[i].clear();
    }
    for (int i = 2, x; i <= n; i++) {
        cin >> x;
        e1[x].push_back(i);
    }
    for (int i = 2, x; i <= n; i++) {
        cin >> x;
        e2[x].push_back(i);
    }
    dfs1(1);
    dfs2(1);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
