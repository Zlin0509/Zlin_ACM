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

set<int> have;
map<int, vi> p;
int n, k;

inline void Zlin() {
    for (auto it: have) p[it].clear();
    have.clear();
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        p[a[i] % k].push_back(a[i]);
        have.insert(a[i] % k);
    }
    ll ans = 0, cnt = 0;
    for (auto it: have)
        if (p[it].size() & 1)
            ++cnt;
    if ((n % 2 == 0 && cnt) || (n % 2 == 1 && cnt >= 2)) {
        cout << -1 << '\n';
        return;
    }
    for (auto it: have) {
        if (p[it].size() & 1) {
            int len = p[it].size();
            vi pre(len + 1), sub(len + 1);
            for (int i = 0; i < len; i += 2) {
                pre[i] = (p[it][i + 1] - p[it][i]) / k;
                if (i - 2 >= 0) pre[i] += pre[i - 2];
            }
            for (int i = len - 1; i >= 0; i -= 2) {
                sub[i] = (p[it][i] - p[it][i - 1]) / k;
                if (i + 2 < len) sub[i] += sub[i + 2];
            }
            ll mx = INT_MAX, tag;
            for (int i = 0; i < len; i++) {
                if (i & 1) {
                    tag = (p[it][i + 1] - p[it][i - 1]) / k;
                    if (i + 3 < len) tag += sub[i + 3];
                    if (i - 3 >= 0) tag += pre[i - 3];
                } else {
                    tag = 0;
                    if (i - 2 >= 0) tag += pre[i - 2];
                    if (i + 2 < len) tag += sub[i + 2];
                }
                mx = min(mx, tag);
            }
            ans += mx;
        } else {
            for (int i = 0; i < p[it].size(); i += 2) {
                ans += (p[it][i + 1] - p[it][i]) / k;
            }
        }
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