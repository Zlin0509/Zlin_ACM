//
// Created by Zlin on 2024/9/24.
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
int n, q, k;
int a[N], f[N], fin[N];
map<int, int> cnt, used;

inline void Zlin() {
    cnt.clear(), used.clear();
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++) cin >> a[i], f[i] = a[i] - i;
    int l = 1, r = 1, ans = 0;
    used[0] = n;
    for (; r <= l + k - 1; r++) {
        --used[cnt[f[r]]];
        ++cnt[f[r]];
        ++used[cnt[f[r]]];
        ans = max(ans, cnt[f[r]]);
    }
    --r;
    fin[r] = ans;
    while (r <= n) {
        --used[cnt[f[l]]];
        if (ans == cnt[f[l]] && !used[cnt[f[l]]])
            ans = cnt[f[l]] - 1;
        --cnt[f[l]];
        ++used[cnt[f[l]]];
        ++l;
        ++r;
        --used[cnt[f[r]]];
        ++cnt[f[r]];
        ++used[cnt[f[r]]];
        ans = max(ans, cnt[f[r]]);
        fin[r] = ans;
    }
    while (q--) {
        cin >> l >> r;
        cout << k - fin[r] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}