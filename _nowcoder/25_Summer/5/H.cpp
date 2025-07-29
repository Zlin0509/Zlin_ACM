//
// Created by Zlin on 2025/7/29.
//

#include "bits/stdc++.h"
#define endl "\n"
#define int long long
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr int N = 110;

int m, s, t;
int n;
int a[N], k[N], b[N], c[N];

struct Node {
    int turn, s, idx, ret, m;
};

inline bool work(int p) {
    queue<Node> pq;
    pq.emplace(0, 0, 0, 0, m);
    int now, nxt, tk, tmp;
    while (!pq.empty()) {
        auto o = pq.front();
        pq.pop();
        if (o.s + o.m * (t - o.turn) >= s) return true;
        now = o.idx, nxt = now + 1;
        if (nxt > n) continue;
        tk = ceil(1.0 * a[nxt] / o.m);
        Node oo;
        if (tk + o.turn <= t) {
            oo.turn = o.turn + tk;
            oo.s = o.s;
            oo.idx = o.idx + 1;
            oo.ret = o.ret + tk;
            oo.m = o.m + k[oo.idx];
            pq.emplace(oo);
        }
        tk = ceil(1.0 * (a[nxt] - c[nxt]) / o.m);
        if (b[nxt] <= o.ret * p) {
            tmp = 0;
            o.ret -= (b[nxt] + p - 1) / p;
        } else {
            tmp = (b[nxt] - o.ret * p + p - 1) / p;
            o.ret = 0;
        }
        if (max(tk, tmp) + o.turn <= t) {
            if (tk <= tmp) {
                oo.turn = o.turn + tmp;
                oo.s = o.s + (tmp - tk) * o.m;
                oo.idx = o.idx + 1;
                oo.ret = o.ret;
                oo.m = o.m + k[oo.idx];
                pq.emplace(oo);
            } else {
                oo.turn = o.turn + tk;
                oo.s = o.s;
                oo.idx = o.idx + 1;
                oo.ret = o.ret + tk - tmp;
                oo.m = o.m + k[oo.idx];
                pq.emplace(oo);
            }
        }
    }
    return false;
}

inline void Zlin() {
    cin >> m >> s >> t >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> k[i] >> b[i] >> c[i];
    int l = 0, r = 1e9, mid;
    while (l < r) {
        mid = l + r >> 1;
        if (work(mid)) r = mid;
        else l = mid + 1;
    }
    cout << (work(l) ? l : -1) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
