//
// Created by Zlin on 2024/11/1.
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

int n;
map<int, int> cnt;

inline void Zlin() {
    cin >> n;
    vi a(n);
    cnt.clear();
    for (int i = 0; i < n; i++) cin >> a[i], cnt[a[i]]++;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    int ans = 0x3f3f3f3f;
    int l = -1, r = a.size() - 1;
    int sl = 0, sr = 0;
    while (a[r] >= a[l + 1] * 2) {
        sr += cnt[a[r]];
        r--;
    }
    ans = min(sl + sr, ans);
    while (l + 1 < a.size() - 1) {
        ++l;
        sl += cnt[a[l]];
        while (r + 1 < a.size() && a[r + 1] < a[l + 1] * 2) {
            r++;
            sr -= cnt[a[r]];
        }
        ans = min(sl + sr, ans);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}