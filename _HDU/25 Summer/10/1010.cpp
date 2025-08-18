//
// Created by Zlin on 2025/8/18.
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

struct Num {
    vi base;

    Num(int m) {
        base.assign(m, 0);
    }

    Num operator&(const Num &b) const {
        Num tmp(base.size());
        for (int i = 0; i < base.size(); i++) tmp.base[i] = base[i] & b.base[i];
        return tmp;
    }

    Num operator|(const Num &b) const {
        Num tmp(base.size());
        for (int i = 0; i < base.size(); i++) tmp.base[i] = base[i] | b.base[i];
        return tmp;
    }

    bool operator<(const Num &b) const {
        for (int i = 0; i < base.size(); i++) {
            if (base[i] > b.base[i]) return false;
            if (base[i] < b.base[i]) return true;
        }
        return true;
    }

    bool check() {
        for (int it: base) if (it) return false;
        return true;
    }
};

int n, m;
vector<Num> a, sub;

inline void Zlin() {
    cin >> n >> m;
    Num x(m), tmp(m);
    for (int j = 0; j < m; j++) {
        char c;
        cin >> c;
        if (c >= 'a' && c <= 'v') tmp.base[j] = c - 'a' + 10;
        else tmp.base[j] = c - '0';
    }
    x = tmp;
    a.clear();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c >= 'a' && c <= 'v') tmp.base[j] = c - 'a' + 10;
            else tmp.base[j] = c - '0';
        }
        a.emplace_back(tmp);
    }
    sub.assign(n, Num(m));
    sub[n - 1] = a[n - 1];
    for (int i = n - 2; ~i; i--) sub[i] = sub[i + 1] & a[i];
    if (x < sub[0]) {
        cout << -1 << endl;
        return;
    }
    Num base(m);
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (tmp.check()) tmp = tmp & a[i];
        else tmp = a[i];
        Num tmp1 = base | tmp | sub[i + 1];
        if (tmp1 < x) {
            ++cnt;
            base = base | tmp;
            fill(tmp.base.begin(), tmp.base.end(), 0);
        }
    }
    cout << cnt + 1 << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
