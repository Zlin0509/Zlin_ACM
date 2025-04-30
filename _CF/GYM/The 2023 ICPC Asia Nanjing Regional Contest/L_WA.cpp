//
// Created by Zlin on 2024/10/14.
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

const int N = 1e5 + 5;

int n;
ll k, ans, cnt, kk, dif;

struct node {
    ll c, w, f;

    bool operator<(const node &x) const {
        if (f != x.f) return f > x.f;
        return c > x.c;
    }
};

inline void Zlin() {
    cin >> n >> k;
    ans = 0;
    vector<node> a;
    for (int i = 1, c, w, f; i <= n; i++) {
        cin >> c >> w >> f;
        a.push_back({c, w, f});
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        kk = a[i].c * a[i].w / k;
        if (kk) {
            ans += a[i].f * kk;
            a[i].c -= k / a[i].w * kk;
        }
        if (a[i].c) {
            ans += a[i].f;
            int l = i;
            cnt = 0;
            while (cnt < k && l < a.size()) {
                dif = min(k - cnt, a[l].c * a[l].w);
                cnt += dif;
                a[l].c -= dif / a[l].w;
                ++l;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
}