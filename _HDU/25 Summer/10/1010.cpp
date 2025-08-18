//
// Created by Zlin on 2025/8/18.
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

constexpr int N = 4e6 + 5;

int tx, ty;

struct Num {
    int m;
    vi base;
    vector<array<int, 5> > tag;

    Num() {
    }

    Num(int mx) {
        m = mx;
        base.assign(m, 0);
        tag.assign(m, {});
    }

    Num operator&(const Num &b) const {
        Num tmp(base.size());
        for (int i = 0; i < base.size(); i++) tmp.base[i] = base[i] & b.base[i];
        return tmp;
    }

    Num operator|(const Num &b) const {
        Num tmp(base.size());
        for (int i = 0; i < base.size(); i++) tmp.base[i] = base[i] | b.base[i];
        return tmp;
    }

    bool operator<(const Num &b) const {
        for (int i = 0; i < base.size(); i++) {
            if (base[i] > b.base[i]) return false;
            if (base[i] < b.base[i]) return true;
        }
        return true;
    }

    bool check() {
        for (int it: base) if (it) return true;
        return false;
    }

    bool find(int i, int j) {
        return base[i] >> j & 1;
    }

    void work(Num &b) {
        int op = 0, sx = m, sy = 0;
        for (int i = m - 1; ~i; i--) {
            for (int j = 0; j < 5; j++) {
                if (base[i] >> j & 1) {
                    if (!b.find(i, j)) op = 1;
                    if (op) tag[i][j] = 1;
                } else if (b.find(i, j)) op = 0;
                if (tag[i][j]) {
                    if (i < sx) sx = i, sy = j;
                    else if (i == sx && j > sy) sy = j;
                }
            }
        }
        if (sx == m) return;
        if (sx > tx) tx = sx, ty = sy;
        else if (sx == tx && sy < ty) ty = sy;
    }
} x;

int n, m, f[N], vis[N], cnt;
vector<Num> a;
vi b;

inline int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }

inline void modify(int u) {
    if (vis[find(u)]) return;
    vis[find(u)] = 1;
    --cnt;
}

inline void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    f[fx] = fy;
}

inline void work(int ix, int jx) {
    bool check = false;
    for (int i = 0; i < n; i++) b[i] = a[i].tag[ix][jx], check |= b[i];
    for (int i = 0; i < n; i++) {
        if (b[i] || vis[find(i)]) {
            modify(i);
            if (i && vis[find(i - 1)]) merge(i, i - 1);
        }
    }
}

inline void Zlin() {
    cin >> n >> m;
    Num tmp(m);
    b.assign(n, 0);
    for (int j = 0; j < m; j++) {
        char c;
        cin >> c;
        if (c >= 'a' && c <= 'v') tmp.base[j] = c - 'a' + 10;
        else tmp.base[j] = c - '0';
    }
    x = tmp;
    a.clear();
    tx = m, ty = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c >= 'a' && c <= 'v') tmp.base[j] = c - 'a' + 10;
            else tmp.base[j] = c - '0';
        }
        a.emplace_back(tmp);
    }
    for (int z = 0; z < n; z++) f[z] = z, vis[z] = 0, a[z].work(x);
    cnt = n;
    int ans = 0;
    cout << tx << ' ' << ty << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 4; ~j; j--) {
            work(i, j);
            if (i >= tx || tx == m) ans = max(ans, cnt);
        }
    }
    ans = max(ans, cnt);
    cout << (ans ? ans : -1) << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
