//
// Created by Zlin on 2024/11/3.
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

ll n, a[200010];

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll dif = -1;
    bool check = true;
    for (int i = 2, k; i <= n; i++) {
        k = a[i] - a[i - 1];
        if (k >= 0) {
            if (dif == -1 || k == dif) dif = k;
            else {
                cout << -1 << '\n';
                return;
            }
        } else check = false;
    }
    if (check || n == 1 || n == 2) {
        cout << 0 << '\n';
        return;
    }
    if (dif == -1) {
        for (int i = 2, k; i <= n; i++) {
            k = a[i - 1] - a[i];
            if (dif == -1 || dif == k) dif = k;
            else {
                cout << -1 << '\n';
                return;
            }
        }
        cout << 0 << '\n';
        return;
    }
    ll c = dif;
    vll all;
    for (int i = 2; i <= n; i++) {
        if (a[i - 1] <= a[i]) continue;
        dif = a[i - 1] + c - a[i];
        all.push_back(dif);
    }
    ll m = all.front();
    for (int it: all) m = gcd(m, it);
    for (int i = 1; i <= n; i++)
        if (a[i] >= m) {
            cout << -1 << '\n';
            return;
        }
    cout << m << ' ' << c << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}