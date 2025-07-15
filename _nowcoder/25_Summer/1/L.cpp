//
// Created by 27682 on 2025/7/15.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

constexpr int N = 5e5 + 10;

int n, q, dif, idx;
ll a[N];

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

    ll qry(int i) {
        ll s = 0;
        while (i > 0) {
            s += t[i];
            i -= i & -i;
        }
        return s;
    }
} t;

struct Query {
    ll p, v;
} Q[N];

vll have;

inline void Zlin() {
    have.clear();
    cin >> n >> q;
    dif = n >> 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        have.push_back(a[i]);
    }
    for (int i = 1; i <= q; i++) {
        cin >> Q[i].p >> Q[i].v;
        a[Q[i].p] += Q[i].v;
        have.push_back(a[Q[i].p]);
    }
    for (int i = q; i; i--) a[Q[i].p] -= Q[i].v;
    sort(have.begin(), have.end());
    have.erase(unique(have.begin(), have.end()), have.end());
    t.init(have.size() + 1);
    for (int i = 1; i <= n; i++) {
        idx = lower_bound(have.begin(), have.end(), a[i]) - have.begin() + 1;
        t.upd(idx, 1);
    }
    for (int i = 1; i <= q; i++) {
        auto [px, vx] = Q[i];
        idx = lower_bound(have.begin(), have.end(), a[px]) - have.begin() + 1;
        t.upd(idx, -1);
        a[px] += vx;
        idx = lower_bound(have.begin(), have.end(), a[px]) - have.begin() + 1;
        t.upd(idx, 1);
        ll l = 0, r = have.size(), mid, res = 0, tmp;
        while (l < r) {
            mid = l + r + 1 >> 1;
            tmp = t.qry(mid);
            if (n - tmp >= dif) {
                l = mid;
                res = max(res, tmp);
            } else r = mid - 1;
        }
        cout << res << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
