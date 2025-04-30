//
// Created by Zlin on 2024/8/31.
//

#include "bits/stdc++.h"

using namespace std;
typedef unsigned long long ll;
const int N = 1e5 + 5;
const int base = 233;
int n, k, cnt;
char s[N], v1[N], v2[N], vers[N];
ll pre[N], sub[N], pw[N];

inline void Zlin() {
    cin >> n >> k >> s + 1;
    cnt = count(s + 1, s + 1 + n, '1');
    for (int i = 1; i <= k; i++) v1[i] = '1', v2[i] = '0';
    int t1 = 0, t2 = 0;
    ll h1 = 0, h2 = 0;
    for (int i = k + 1; i <= n; i++) {
        v1[i] = (v1[i - k] == '0' ? '1' : '0');
        v2[i] = (v2[i - k] == '0' ? '1' : '0');
    }
    for (int i = 1; i <= n; i++) {
        h1 = h1 * base + v1[i];
        t1 += v1[i] == '1';
        h2 = h2 * base + v2[i];
        t2 += v2[i] == '1';
    }
    if (t1 != cnt)h1 = -1;
    if (t2 != cnt)h2 = -1;
    strcpy(vers + 1, s + 1);
    reverse(vers + 1, vers + 1 + n);
    pre[0] = sub[0] = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] * base + s[i];
        sub[i] = sub[i - 1] * base + vers[i];
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        ll h = (pre[n] - pre[i] * pw[n - i]) * pw[i] + (sub[n] - sub[n - i] * pw[i]);
        if (h == h1 || h == h2) {
            ans = i;
            break;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    pw[0] = 1;
    for (int i = 1; i < N; i++) pw[i] = pw[i - 1] * base;
    while (ttt--) Zlin();
}