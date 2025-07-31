//
// Created by Zlin on 2025/7/31.
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

constexpr int N = 1e5 + 10;

inline void Zlin() {
    int n, q;
    cin >> n >> q;
    vi p(n);
    for (int &it: p) {
        cin >> it;
        --it;
    }
    int siz1 = 310, siz2 = (n + siz1 - 1) / siz1;
    vector cnt(siz2, vi(siz2));
    // 第一维对应p 第二维对应a
    for (int i = 0; i < siz2; i++) {
        int L = i * siz1, R = min(n, L + siz1);
        for (int j = L; j < R; j++) ++cnt[i][p[j] / siz1];
    }
    // 前缀和处理 用来统计对于每一块a p中一段区间内包含多少个
    vector pre(siz2 + 1, vi(siz2));
    for (int i = 0; i < siz2; i++) {
        for (int j = 0; j < siz2; j++) {
            pre[i + 1][j] = pre[i][j] + cnt[i][j];
        }
    }
    vector<vector<pii> > occ(n);
    for (int i = 0; i < siz2; i++) {
        int L = i * siz1, R = min(n, L + siz1);
        vi val;
        for (int j = L; j < R; j++) val.emplace_back(p[j]);
        sort(val.begin(), val.end());
        for (int l = 0, r; l < val.size(); l = r) {
            r = l;
            while (r < val.size() && val[r] <= val[l]) ++r;
            occ[val[l]].emplace_back(i, r - l);
        }
    }
    vll a(n, 0), tag(siz2, 0), sum(siz2, 0);
    auto add1 = [&](int i, ll x) {
        a[i] += x;
        for (auto [idx, c]: occ[i]) sum[idx] += x * c;
    };
    auto add2 = [&](int l, int r, ll x) {
        int bl = l / siz1, br = r / siz1;
        if (bl == br) for (int i = l; i <= r; i++) add1(i, x);
        else {
            int tmp = (bl + 1) * siz1 - 1;
            for (int i = l; i <= tmp; i++) add1(i, x);
            tmp = br * siz1;
            for (int i = tmp; i <= r; i++) add1(i, x);
            for (int i = bl + 1; i <= br - 1; i++) tag[i] += x;
        }
    };
    auto get1 = [&](int i) {
        return a[i] + tag[i / siz1];
    };
    auto get2 = [&](int l, int r) {
        ll ans = 0;
        int bl = l / siz1, br = r / siz1;
        if (bl == br) for (int i = l; i <= r; i++) ans += get1(p[i]);
        else {
            int tmp = (bl + 1) * siz1 - 1;
            for (int i = l; i <= tmp; i++) ans += get1(p[i]);
            tmp = br * siz1;
            for (int i = tmp; i <= r; i++) ans += get1(p[i]);
            ++bl, --br;
            if (bl <= br) {
                for (int i = bl; i <= br; i++) ans += sum[i];
                for (int j = 0; j < siz2; j++) {
                    int k = pre[br + 1][j] - pre[bl][j];
                    ans += 1ll * k * tag[j];
                }
            }
        }
        return ans;
    };
    ll ans = 0;
    while (q--) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            ll l, r, x;
            cin >> l >> r >> x;
            l = (l ^ ans) - 1, r = (r ^ ans) - 1, x ^= ans;
            add2(l, r, x);
        } else {
            ll l, r;
            cin >> l >> r;
            l = (l ^ ans) - 1, r = (r ^ ans) - 1;
            ans = get2(l, r);
            cout << ans << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
