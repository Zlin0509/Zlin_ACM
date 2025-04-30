//
// Created by Zlin on 2024/9/19.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 2e5 + 5;
ll n, f[N], dep[N], cnt[N];
ll w, sum[N];
vi have[N];

inline void Zlin() {
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        have[i].clear();
        cnt[i] = sum[i] = 0ll;
    }
    for (int i = 2; i <= n; i++) {
        ll l, r;
        cin >> f[i];
        dep[i] = dep[f[i]] + 1;
        if (f[i] == i - 1) have[i].push_back(i), ++cnt[i];
        else {
            l = i - 1, r = i;
            if (dep[l] > dep[r]) swap(l, r);
            while (dep[r] > dep[l]) {
                ++cnt[i];
                have[r].push_back(i);
                r = f[r];
            }
            while (l != r) {
                have[l].push_back(i);
                have[r].push_back(i);
                l = f[l];
                r = f[r];
                cnt[i] += 2;
            }
        }
    }
    ll k = n;
    while (k != 1) {
        ++cnt[1];
        have[k].push_back(1);
        k = f[k];
    }
    ll ans = n * w, x, y, ss = 0, tot = n;
    for (int t = 1; t < n; t++) {
        cin >> x >> y;
        ss += y;
        ans -= y * (ll) (tot - have[x].size());
        for (int i: have[x]) {
            sum[i] += y;
            --cnt[i];
            if (!cnt[i]) {
                ans = ans - w + ss;
                --tot;
            }
        }
        cout << ans << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}