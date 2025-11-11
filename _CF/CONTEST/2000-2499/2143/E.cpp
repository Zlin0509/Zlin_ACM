//
// Created by 27682 on 2025/11/5.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline void Zlin() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c = 0;
    for (const auto &it: s) c += it == '(';
    if (abs(c - n / 2) & 1) {
        cout << -1 << endl;
        return;
    }
    c = 0;
    for (const auto &it: s) {
        c += it == '(' ? 1 : -1;
        if (c < 0) break;
    }
    if (!c) {
        cout << s << endl;
        return;
    }
    c = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            c = i;
            break;
        }
    }
    if (!c) {
        cout << -1 << endl;
        return;
    }
    if (n / 2 & 1) {
        for (int i = 0; i < n / 4; i++) cout << "(";
        for (int i = 0; i < n / 4; i++) cout << ")";
        for (int i = 0; i <= n / 4; i++) cout << "(";
        for (int i = 0; i <= n / 4; i++) cout << ")";
    } else {
        for (int i = 0; i < n / 2; i++) cout << "(";
        for (int i = 0; i < n / 2; i++) cout << ")";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}