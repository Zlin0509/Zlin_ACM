//
// Created by Zlin on 2024/10/4.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n, m;
ll k;

struct ss {
    int id, val;
    ll l, r;

    bool operator<(const ss &x) const {
        if (val != x.val)
            return val > x.val;
        return r > x.r;
    }
};

inline void Zlin() {
    cin >> n >> m >> k;
    vector<ss> a(n, {0, 0, 0, 0});
    vector<vector<ll>> p(n, vector<ll>(m, 0));
    for (int i = 0; i < n; i++) {
        cin >> a[i].val;
        a[i].id = i;
        for (int j = 0; j < m; j++) {
            cin >> p[i][j];
            if (p[i][j] != -1) {
                a[i].r += p[i][j];
                a[i].l += p[i][j];
            } else {
                a[i].r += k;
            }
        }
    }
    sort(a.begin(), a.end());
    for (int j = 0; j < m; j++) {
        if (p[a[0].id][j] != -1) continue;
        p[a[0].id][j] = k;
    }
    ll tag = a[0].r, dif;
    for (int i = 1; i < n; i++) {
        if (a[i].val < a[i - 1].val) --tag;
        tag = min(tag, a[i].r);
        if (tag < a[i].l) {
            cout << "No" << '\n';
            return;
        }
        dif = tag - a[i].l;
        for (int j = 0; j < m; j++) {
            if (p[a[i].id][j] != -1) continue;
            p[a[i].id][j] = min(dif, k);
            dif -= p[a[i].id][j];
        }
    }
    cout << "Yes" << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << p[i][j] << ' ';
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}