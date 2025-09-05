//
// Created by 27682 on 2025/9/5.
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

int n, m;
ll ans[N];
pii a[N];

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
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n);
    t.init(n);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i].first;
        ll res = 1ll * i * a[i].first - sum + t.qry1(a[i].second);
        t.upd(a[i].second, 1);
        if (res > m - 2) ans[a[i].second] = -1;
        else ans[a[i].second] = res;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
