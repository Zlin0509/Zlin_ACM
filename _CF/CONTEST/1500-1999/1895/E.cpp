//
// Created by 27682 on 2025/5/20.
//

#include "bits/stdc++.h"
#define endl '\n'
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

struct card {
    int s, t;
};

int n, m;
vector<card> a, b;
vi have, sz[2], res;


inline void Zlin() {
    have.clear();
    cin >> n;
    a.assign(n, card());
    for (int i = 0; i < n; i++) {
        cin >> a[i].s;
        have.push_back(a[i].s);
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].t;
        have.push_back(a[i].t);
    }
    cin >> m;
    b.assign(m, card());
    for (int i = 0; i < m; i++) {
        cin >> b[i].s;
        have.push_back(b[i].s);
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i].t;
        have.push_back(b[i].t);
    }
    sort(have.begin(), have.end());
    have.erase(unique(have.begin(), have.end()), have.end());
    int siz = have.size();
    sz[0].assign(siz + 4, 0);
    sz[1].assign(siz + 4, 0);
    res.assign(siz + 4, -1);
    for (auto &[s, t]: a) {
        s = lower_bound(have.begin(), have.end(), s) - have.begin() + 1;
        t = lower_bound(have.begin(), have.end(), t) - have.begin() + 1;
        sz[0][s] = max(sz[0][s], t);
    }
    for (auto &[s, t]: b) {
        s = lower_bound(have.begin(), have.end(), s) - have.begin() + 1;
        t = lower_bound(have.begin(), have.end(), t) - have.begin() + 1;
        sz[1][s] = max(sz[1][s], t);
    }
    for (int i = siz - 1; i; i--) {
        sz[0][i] = max(sz[0][i], sz[0][i + 1]);
        sz[1][i] = max(sz[1][i], sz[1][i + 1]);
    }
    for (int i = siz; i; i--) {
        int now = i, cnt = 0, used1 = 0, used2 = 0;
        while (now < siz && sz[cnt ^ 1][now + 1]) {
            if (!cnt && res[now] != -1) {
                cnt = res[now];
                break;
            }
            if (used2 && now == used2) {
                cnt = 2;
                break;
            }
            if (!used1) {
                used1 = now;
            } else {
                used2 = used1;
                used1 = now;
            }
            now = sz[cnt ^ 1][now + 1];
            cnt ^= 1;
        }
        res[i] = cnt;
    }
    vi ans(3);
    for (auto [s, t]: a) ans[res[t]]++;
    cout << ans[0] << ' ' << ans[2] << ' ' << ans[1] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
