//
// Created by 27682 on 2025/7/17.
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

constexpr int N = 1e5 + 10;

int n, t0, cnt;
string s;

inline void Zlin() {
    cin >> n >> t0 >> s;
    s = ' ' + s;
    vi pos;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            pos.emplace_back(i);
        }
    }
    ll ans = 0;
    vi have;
    int val;
    if (!pos.empty()) {
        val = n - pos.back() + pos[0] - 1 - t0 * 2;
        ans += max(0, val);
        have.emplace_back(val);
        for (int i = 0; i + 1 < pos.size(); i++) {
            val = pos[i + 1] - pos[i] - 1 - t0 * 2;
            ans += max(0, val);
            have.emplace_back(val);
        }
        sort(have.begin(), have.end());
        int tag = have.back();
        ans -= max(0, tag);
        ans += max(0, tag + t0 - 1);
    } else ans = n;
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
