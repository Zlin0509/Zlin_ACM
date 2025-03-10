//
// Created by Zlin on 2024/9/12.
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

ull n, k;

struct ss {
    ull a, b;
} s[N];

inline void Zlin() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> s[i].a;
    for (int i = 1; i <= n; i++) cin >> s[i].b;
    ull l = 0, r = 1e9 + 5, mid, cnt2, ans = 0, sum, cnt, dif;
    while (l < r) {
        sum = cnt = cnt2 = 0;
        mid = l + r >> 1;
        for (int i = 1; i <= n; i++) {
            if (s[i].a < mid) continue;
            dif = (s[i].a - mid) / s[i].b;
            if (s[i].a - dif * s[i].b == mid) ++cnt2;
            else ++dif;
            cnt += dif;
            sum += (2ll * s[i].a - s[i].b * (dif - 1ll)) * dif / 2ll;
            if (cnt > k) break;
        }
        if (cnt < k && cnt2) {
            sum += min(k - cnt, cnt2) * mid;
            cnt = k;
        }
        if (cnt <= k) r = mid, ans = max(ans, sum);
        else l = mid + 1;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}