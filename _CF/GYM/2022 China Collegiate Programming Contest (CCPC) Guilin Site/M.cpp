//
// Created by 27682 on 2025/9/3.
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

constexpr int N = 3e5 + 10;

int n, m, p[N], tag = 1, cnt = 1;
string s;
ll ans = 0;

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
} t;

inline void Zlin() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> p[i];
    cin >> s;
    t.init(n);
    for (int i = n; i >= 1; i--) {
        ans += t.qry1(p[i]);
        t.upd(p[i], 1);
    }
    cout << ans << endl;
    for (char it: s) {
        if (it == 'S') {
            if (cnt) {
                ans -= p[tag] - 1;
                ans += n - p[tag];
                ++tag;
                if (tag > n) tag = 1;
            } else {
                int id = tag - 1;
                if (id < 1) id = n;
                ans -= n - p[id];
                ans += p[id] - 1;
                --tag;
                if (tag < 1) tag = n;
            }
        } else cnt ^= 1;
        if (cnt) {
            cout << ans % 10;
        } else {
            cout << (1ll * n * (n - 1) / 2 - ans) % 10;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
