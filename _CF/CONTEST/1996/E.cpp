//
// Created by Zlin on 2024/8/17.
//
#include"bits/stdc++.h"

using namespace std;

typedef long long ll;

const ll mo = 1e9 + 7;
const int N = 2e5 + 10;

inline void Zlin() {
    ll ans = 0, cnt1 = 0, cnt2 = 0;
    string x;
    map<ll, ll> sum;
    sum[0] = 1;
    cin >> x;
    for (int i = 0; i < x.length(); i++) {
        x[i] == '0' ? ++cnt1 : ++cnt2;
        ans = (ans + sum[cnt1 - cnt2] * (x.length() - i)) % mo;
        sum[cnt1 - cnt2] = (sum[cnt1 - cnt2] + i + 2) % mo;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}