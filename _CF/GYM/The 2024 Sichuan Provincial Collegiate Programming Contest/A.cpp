//
// Created by Zlin on 2025/5/24.
//

#include "bits/stdc++.h"
#define endl "\n"
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

constexpr int N = 3e5 + 10;


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

int n, a[N], used[N];
ll ans = 0;

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    t.init(n + 10);
    used[a[n]] = 1;
    t.upd(a[n], 1);
    int tmp = 0;
    for (int i = n - 1, now; i; i--) {
        now = t.qry1(a[i]);
        if (now < tmp) ans += tmp - now;
        tmp = now, used[a[i]] = 1;
        if (!used[a[i] - 1]) t.upd(a[i], 1);
        if (t.qry2(a[i] + 1, a[i] + 1)) t.upd(a[i] + 1, -1);
    }
    ans += tmp;
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
