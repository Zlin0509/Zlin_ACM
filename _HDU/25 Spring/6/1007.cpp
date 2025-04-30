//
// Created by 27682 on 2025/4/11.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline void Zlin() {
    int n;
    cin >> n;
    vi val(n);
    for (int &it: val) cin >> it;
    vi a, b;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        c == 'R' ? a.push_back(val[i]) : b.push_back(val[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans = 0;
    while (!a.empty() && !b.empty()) {
        ans += a.back();
        a.pop_back();
        ans += b.back();
        b.pop_back();
    }
    if (!a.empty()) ans += a.back();
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
