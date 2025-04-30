//
// Created by 27682 on 2025/3/26.
//

#include "bits/stdc++.h"
#define endl '\n'
#define int long long
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int mo = 998244353;

struct Ftree {
private:
    vi t;

public:
    void init(int n) {
        t.assign(n + 1, 0);
    }

    void upd(int i, int val) {
        while (i < t.size()) {
            t[i] = (t[i] + val + mo) % mo;
            i += i & -i;
        }
    }

    int query(int i) {
        int res = 0;
        while (i) {
            res = (res + t[i]) % mo;
            i -= i & -i;
        }
        return res;
    }

    int query1(int l, int r) {
        if (l > r || !l) return 0;
        return (query(r) - query(l - 1) + mo) % mo;
    }
} t00, t01, t10, t11, ans;


constexpr int N = 2e5;

ll fac[N + 10];

constexpr ll mo = 998244353;

inline void Zlin() {
    string s;
    int n, q;
    cin >> s >> q;
    n = s.length();
    s = ' ' + s;
    t00.init(n + 1);
    t10.init(n + 1);
    t01.init(n + 1);
    t11.init(n + 1);
    ans.init(n + 1);
    for (int i = 1, val; i <= n; i++) {
        val = fac[n - i];
        s[i] == '1' ? t11.upd(i, val) : t01.upd(i, val);
        val = fac[i - 1];
        s[i] == '1' ? t10.upd(i, val) : t00.upd(i, val);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + fac[n - i] + fac[i - 1] * (s[i] == '1' ? t01.query1(i + 1, n) : t11.query1(i + 1, n)) % mo) % mo;
    }
    while (q--) {
        int v, val;
        cin >> v;
        if (s[v] == '1') {
            s[v] = '0';
            t10.upd(v, -fac[v - 1]);
            t00.upd(v, fac[v - 1]);
            t11.upd(v, -fac[n - v]);
            t01.upd(v, fac[n - v]);
            val = (fac[n - v] * (t10.query1(1, v - 1) - t00.query1(1, v - 1)) % mo +
                   fac[v - 1] * (t11.query1(v + 1, n) - t01.query1(v + 1, n)) % mo) % mo;
        } else {
            s[v] = '1';
            t00.upd(v, -fac[v - 1]);
            t10.upd(v, fac[v - 1]);
            t01.upd(v, -fac[n - v]);
            t11.upd(v, fac[n - v]);
            val = (fac[n - v] * (t00.query1(1, v - 1) - t10.query1(1, v - 1)) % mo +
                   fac[v - 1] * (t01.query1(v + 1, n) - t11.query1(v + 1, n)) % mo) % mo;
        }
        ans = (ans + val + mo) % mo;
        cout << ans << ' ';
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    fac[0] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = fac[i - 1] * 2 % mo;
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
