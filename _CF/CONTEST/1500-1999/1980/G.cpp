//
// Created by 27682 on 2025/5/14.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

struct Trie {
private:
    struct Trienode {
        int cnt;
        Trienode *nxt[2];

        Trienode() {
            cnt = 0;
            nxt[0] = nxt[1] = nullptr;
        }
    } root;

public:
    void init() {
        root = Trienode();
    }

    void ins(int x) {
        Trienode *cur = &root;
        for (int i = 31; ~i; i--) {
            int bit = x >> i & 1;
            if (!cur->nxt[bit]) cur->nxt[bit] = new Trienode();
            cur = cur->nxt[bit];
            cur->cnt++;
        }
    }

    ll cal(ll x) {
        ll res = 0;
        Trienode *cur = &root;
        for (int i = 31; ~i; i--) {
            int bit = x >> i & 1 ^ 1;
            if ((cur->nxt[0] == nullptr || cur->nxt[0]->cnt == 0) && (cur->nxt[1] == nullptr || cur->nxt[1]->cnt == 0))
                return 0;
            if (cur->nxt[bit] == nullptr || !cur->nxt[bit]->cnt) {
                cur = cur->nxt[bit ^ 1];
            } else {
                res += 1 << i;
                cur = cur->nxt[bit];
            }
        }
        return res;
    }

    void erase(int x) {
        Trienode *cur = &root;
        for (int i = 31; ~i; i--) {
            int bit = x >> i & 1;
            cur = cur->nxt[bit];
            cur->cnt--;
        }
    }
} t[2];

constexpr int N = 2e5 + 10;
int n, m;
ll val[N], dep[N];

struct edge {
    int v, val;
};

vector<edge> e[N];

inline void dfs(int u, int fa) {
    t[dep[u] & 1].ins(val[u]);
    for (auto [v, w]: e[u]) {
        if (v == fa) continue;
        val[v] = val[u] ^ w;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

inline void Zlin() {
    t[0].init(), t[1].init();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        e[i].clear();
        val[i] = dep[i] = 0;
    }
    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    dfs(1, 0);
    int sum = 0;
    while (m--) {
        char op;
        cin >> op;
        if (op == '^') {
            int y;
            cin >> y;
            sum ^= y;
        } else {
            ll v, x;
            cin >> v >> x;
            t[dep[v] & 1].erase(val[v]);
            ll ans = max(t[dep[v] & 1].cal(val[v] ^ x), t[dep[v] & 1 ^ 1].cal(val[v] ^ x ^ sum));
            t[dep[v] & 1].ins(val[v]);
            cout << ans << ' ';
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
