//
// Created by 27682 on 2025/7/22.
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

ll a, b, c;
int la, lb, lc, cnt;
vi res;

inline void Zlin() {
    res.clear();
    cin >> a >> b >> c;
    if (!a && !b) {
        cout << (c ? -1 : 0) << endl;
        return;
    }
    if (!a) {
        res.emplace_back(3);
        a ^= b;
    }
    if (!b) {
        res.emplace_back(4);
        b ^= a;
    }
    la = lb = lc = -1, cnt = 0;
    for (int i = 31; ~i; i--) {
        if (a >> i & 1 && la == -1) la = i;
        if (b >> i & 1 && lb == -1) lb = i;
        if (c >> i & 1 && lc == -1) lc = i;
    }
    if (la > lb) {
        res.emplace_back(4);
        b ^= a;
        lb = la;
    }
    if (la < lb) {
        res.emplace_back(3);
        a ^= b;
        la = lb;
    }
    if (lb >= lc) {
        while (lb >= 0) {
            if ((c >> lb & 1) != (a >> lb & 1)) {
                res.emplace_back(3);
                a ^= b;
            }
            res.emplace_back(2);
            b >>= 1;
            --lb;
        }
        res.emplace_back(4);
        b ^= a;
    } else {
        int cnt = 0;
        while (lb >= 0) {
            if ((c >> (lc - cnt) & 1) != (a >> (la - cnt) & 1)) {
                res.emplace_back(3);
                a ^= b;
            }
            if (lb != 0) {
                res.emplace_back(2);
                b >>= 1;
            }
            --lb;
            ++cnt;
        }
        while (cnt <= lc) {
            res.emplace_back(1);
            a <<= 1;
            ++la;
            if ((c >> (lc - cnt) & 1) != (a >> (la - cnt) & 1)) {
                res.emplace_back(3);
                a ^= b;
            }
            ++cnt;
        }
        res.emplace_back(2);
        b >>= 1;
        res.emplace_back(4);
        b ^= a;
    }
    if (res.size() > 64)
        while (1) {
        };
    if (a != b || b != c) cout << 1 / 0 << endl;
    cout << res.size() << endl;
    for (int it: res) cout << it << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
