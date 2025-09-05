//
// Created by 27682 on 2025/9/5.
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

constexpr int N = 5e5 + 10;

ll n, m, k;
ll cnt[N];

set<vi> have;

inline void dfs(vi &a) {
    if (a.size() == k) {
        int val = 0;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < i; j++) {
                val += a[i] ^ a[j];
            }
        }
        if (val == n) {
            vi b = a;
            sort(b.begin(), b.end());
            have.insert(b);
        }
        ++cnt[val];
        return;
    }
    for (int i = 0; i <= m; i++) {
        a.emplace_back(i);
        dfs(a);
        a.pop_back();
    }
}

inline void Zlin() {
    cin >> n >> m >> k;
    vi a;
    dfs(a);
    // for (auto &it: have) {
    //     for (auto iit: it) cout << iit << ' ';
    //     cout << endl;
    // }
    cout << cnt[n] << endl;
    int mx = 0;
    for (int i = 0; i < 100; i++) {
        cout << cnt[i] << ' ';
        if (cnt[i]) mx = i;
    }
    cout << endl << mx << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}