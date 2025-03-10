//
// Created by Zlin on 2024/9/4.
//

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;

inline void Zlin() {
    ll n, lx, ans = 0;
    cin >> n >> lx;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].second >> a[i].first;
    sort(a.begin(), a.end());
    for (int l = 0; l < n; l++) {
        multiset<int> mx;
        ll sum = 0;
        for (int r = l; r < n; r++) {
            sum += a[r].second;
            mx.insert(a[r].second);
            while (mx.size() && a[r].first - a[l].first + sum > lx) {
                sum -= *mx.rbegin();
                mx.erase(mx.find(*mx.rbegin()));
            }
            ans = max(ans, (ll) mx.size());
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