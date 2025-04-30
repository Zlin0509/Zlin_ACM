//
// Created by Zlin on 2024/10/5.
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

const ll inf = 1e9;

struct node {
    ll l = -inf, r = inf;
};

inline void Zlin() {
    int n;
    cin >> n;
    pll a[n];
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    auto check = [&](ll v) {
        node r1, r2;
        r1.l = r1.r = a[0].second;
        for (int i = 1; i < n; i++) {
            r1.l -= v * (a[i].first - a[i - 1].first);
            r2.l -= v * (a[i].first - a[i - 1].first);
            r1.r += v * (a[i].first - a[i - 1].first);
            r2.r += v * (a[i].first - a[i - 1].first);
            r1.l = max(-inf, r1.l);
            r2.l = max(-inf, r2.l);
            r1.r = min(inf, r1.r);
            r2.r = min(inf, r2.r);
            ll d = a[i].second;
            if (d >= r1.l && d <= r1.r && d >= r2.l && d <= r2.r) {
                r2.l = min(r2.l, r1.l);
                r2.r = max(r2.r, r1.r);
                r1.l = r1.r = d;
            } else if (d >= r1.l && d <= r1.r) {
                r1.l = r1.r = d;
            } else if (d >= r2.l && d <= r2.r) {
                r2.l = r2.r = d;
            } else return false;
        }
        return true;
    };

    ll l = 0, r = 1e9, ans = -1, mid;
    while (l < r) {
        mid = l + r >> 1;
        if (check(mid)) ans = mid, r = mid;
        else l = mid + 1;
    }
    if (check(l)) ans = l;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}