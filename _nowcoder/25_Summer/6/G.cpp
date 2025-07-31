//
// Created by Zlin on 2025/7/31.
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

constexpr int N = 2e5 + 10;

int n, q, val[N];
string s;

struct Ftree {
private:
    vi t;

public:
    void init(int n) {
        t.assign(n + 1, 0);
    }

    void upd(int i, int v) {
        while (i < t.size()) {
            t[i] += v;
            i += i & -i;
        }
    }

    int qry1(int i) {
        int s = 0;
        while (i > 0) {
            s += t[i];
            i -= i & -i;
        }
        return s;
    }

    int qry2(int l, int r) {
        return qry1(r) - qry1(l - 1);
    }
} t0, t1;

set<int> p0, p1;

inline void Zlin() {
    cin >> n >> q >> s;
    s = ' ' + s;
    t0.init(n + 1), t1.init(n + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'L') {
            val[i] = 0;
            p0.insert(i);
            t0.upd(i, 1);
        } else {
            val[i] = 1;
            p1.insert(i);
            t1.upd(i, 1);
        }
    }
    while (q--) {
        int pos;
        cin >> pos;
        if (val[pos]) {
            t1.upd(pos, -1);
            t0.upd(pos, 1);
            p1.erase(pos);
            p0.insert(pos);
        } else {
            t0.upd(pos, -1);
            t1.upd(pos, 1);
            p0.erase(pos);
            p1.insert(pos);
        }
        val[pos] ^= 1;
        int ans = 0;
        if (!p0.empty()) {
            pos = *prev(p0.end());
            ans = max(ans, t1.qry2(1, pos));
        }
        if (!p1.empty()) {
            pos = *p1.begin();
            ans = max(ans, t0.qry2(pos, n));
        }
        cout << ans << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
