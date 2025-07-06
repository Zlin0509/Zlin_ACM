//
// Created by 27682 on 2025/7/6.
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

constexpr int N = 4e5 + 10;

set<int> idx[N];

inline void Zlin() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) idx[i].clear();
    vi a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
        idx[a[i]].insert(i);
    }
    if (k <= 2) {
        cout << "YES" << endl;
        return;
    }
    sort(b.begin(), b.end());
    vi have;
    for (int i = 0; i < k - 1; i++) have.push_back(b[i]);
    sort(have.begin(), have.end());
    have.erase(unique(have.begin(), have.end()), have.end());
    if (have.size() == 1) {
        cout << "YES" << endl;
        return;
    }
    vi ii;
    for (int it: have) {
        if (it == have.back()) break;
        for (int id: idx[it]) ii.push_back(id);
    }
    sort(ii.begin(), ii.end());
    int l = 0, r = ii.size() - 1;
    while (l < r) {
        if (a[ii[l]] != a[ii[r]]) {
            cout << "NO" << endl;
            return;
        }
        ++l, --r;
    }
    int res = k - 1 - ii.size(), tt = have.back();
    l = 0, r = ii.size() - 1;
    int lx, rx;
    if (res & 1) {
        if (ii.size() & 1) ++res;
        else {
            vi tmp;
            tmp.push_back(ii[ii.size() / 2 - 1]);
            for (int i = ii[ii.size() / 2 - 1] + 1; i < ii[ii.size() / 2]; i++) if (a[i] == tt) tmp.push_back(i);
            tmp.push_back(ii[ii.size() / 2]);
            if (tmp.size() & 1 || tmp[tmp.size() / 2 - 1] + 1 != tmp[tmp.size() / 2]) --res;
            else ++res;
        }
    }
    while (res && l <= r && !idx[tt].empty()) {
        lx = ii[l], rx = ii[r];
        while (!idx[tt].empty() && res && *idx[tt].begin() < lx && *prev(idx[tt].end()) > rx) {
            idx[tt].erase(prev(idx[tt].end()));
            idx[tt].erase(idx[tt].begin());
            res -= 2;
        }
        while (!idx[tt].empty() && *idx[tt].begin() < lx) idx[tt].erase(idx[tt].begin());
        while (!idx[tt].empty() && *prev(idx[tt].end()) > rx) idx[tt].erase(prev(idx[tt].end()));
        ++l, --r;
    }
    if (res) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
