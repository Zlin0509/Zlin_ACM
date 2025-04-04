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
int n, q;
int a[N];
ll sum[N], ans;

inline void Zlin() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i - 1] + a[i];
    ll l, r, li, ri, sl, sr;
    while (q--) {
        cin >> l >> r;
        li = (l - 1) / n, ri = (r - 1) / n;
        if (li != ri)
            ans = sum[n] * (ri - li - 1);
        else
            ans = 0;
        l -= li * n, r -= ri * n;
        l += li, r += ri;
//        cout << li << ' ' << ri << ' ';
        if (li != ri) {
            if (l <= n) {
                sl = sum[n] - sum[l - 1] + sum[li];
            } else {
                sl = sum[li] - sum[l - n - 1];
            }
            if (r <= n) {
                sr = sum[r] - sum[ri];
            } else {
                sr = sum[n] - sum[ri] + sum[r - n];
            }
            ans += sl + sr;
        } else {
            if (r <= n) ans += sum[r] - sum[l - 1];
            else if (l > n) ans += sum[r - n] - sum[l - n - 1];
            else ans += sum[r - n] + sum[n] - sum[l - 1];
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}