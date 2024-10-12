//
// Created by Zlin on 2024/10/8.
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

inline void Zlin() {
    int n;
    cin >> n;
    vi a(n + 1);
    a[0] = -1;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l, r = n;
    vector<pii> ans;
    while (r) {
        l = 1;
        while (a[l] < a[r]) ++l;
        if (l != r) {
            ans.push_back({l, r});
            sort(a.begin() + l, a.begin() + r + 1);
        }
        while (a[r] == r) --r;
    }
    cout << ans.size() << '\n';
    for (auto [l, r]: ans) cout << l << ' ' << r << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
}