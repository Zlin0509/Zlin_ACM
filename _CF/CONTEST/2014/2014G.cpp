//
// Created by Zlin on 2024/10/23.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

struct ss {
    ll val, cnt;

    bool operator<(const ss &x) const {
        return val < x.val;
    }
};

const int N = 1e6 + 5;
ll n, m, k;

void add(ss &x, ss y, ll tag) {
    if (x.cnt / m + tag - 1 >= y.val) return;
    if ((x.cnt + y.cnt) / m + tag - 1 <= y.val) {
        x = {y.val, x.cnt + y.cnt};
    } else {
        x = {y.val, (y.val - tag + 1) * m};
    }
}

void add2(ss &x, ss y) {
    x = {y.val, x.cnt + y.cnt};
}

inline void Zlin() {
    cin >> n >> m >> k;
    vi d(n), a(n);
    for (int i = 0; i < n; i++) cin >> d[i] >> a[i];
    priority_queue<ss> q;
    ss u;
    ll l = 0, ans = 0, dif, tag;
    while (l < n - 1) {
        u = {0, 0};
        tag = d[l];
        dif = d[l + 1] - d[l];
        q.push({d[l] + k - 1, a[l]});
        while (u.cnt / m < dif && !q.empty()) {
            add(u, q.top(), tag);
            q.pop();
        }
        tag = min(dif, u.cnt / m);
        ans += tag;
        u.cnt -= m * tag;
        if (u.cnt) q.push(u);
        if (tag != dif) {
            u = {0, 0};
            tag = (dif - tag) * m;
            while (u.cnt < tag && !q.empty()) {
                add2(u, q.top());
                q.pop();
            }
            if (u.cnt > tag && u.val >= d[l + 1]) q.push({u.val, u.cnt - tag});
        }
        ++l;
    }
    u = {0, 0};
    q.push({d[l] + k - 1, a[l]});
    while (!q.empty()) {
        add(u, q.top(), d[l]);
        q.pop();
    }
    ans += u.cnt / m;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}