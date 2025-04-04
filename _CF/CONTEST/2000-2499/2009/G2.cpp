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

constexpr int N = 2e5 + 10;

inline void Zlin() {
    int n, k, q;
    cin >> n >> k >> q;
    vi a(n + 1), f(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= i;
    }
    unordered_map<int, int> cnt, used;
    multiset<int> have;
    int l, r = 1;
    while (r <= k) {
        if (cnt[a[r]]) have.erase(have.find(cnt[a[r]]));
        ++cnt[a[r]];
        have.insert(cnt[a[r]]);
        ++r;
    }
    for (l = 1; l <= n - k + 1; l++) {
        while (r - l < k) {
            if (cnt[a[r]]) have.erase(have.find(cnt[a[r]]));
            ++cnt[a[r]];
            have.insert(cnt[a[r]]);
            ++r;
        }
        f[l] = k - *prev(have.end());
    }
    for (int i = 1; i <= n; i++)
        cout << f[i] << " ";
    cout << endl;

    while (q--) {
        cin >> l >> r;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
