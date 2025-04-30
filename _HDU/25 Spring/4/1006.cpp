//
// Created by 27682 on 2025/3/28.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct Ftree {
private:
    vll t;

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

    ll qry1(int i) {
        ll s = 0;
        while (i > 0) {
            s += t[i];
            i -= i & -i;
        }
        return s;
    }

    ll qry2(int l, int r) {
        return qry1(r) - qry1(l - 1);
    }
} t;

inline void Zlin() {
    int n, q;
    cin >> n >> q;
    t.init(n + 10);
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        t.upd(i, x);
    }
    ll ans = 0, val, cnt = 0;
    for (int i = 1; i <= q; i++) {
        ll op;
        int x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            val = t.qry2(x, x);
            t.upd(x, y - val);
        } else {
            val = t.qry1(y) / 100 - t.qry1(x - 1) / 100;
            val *= ++cnt;
            ans ^= val;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
