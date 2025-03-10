//
// Created by Zlin on 2024/11/25.
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

const int N = 2e5 + 5;
int n;
int a[N];

inline void Zlin() {
    cin >> n;
    a[1] = 1;
    for (int i = 1, x; i < n; i++) {
        cout << "? " << i << ' ' << i + 1 << '\n';
        cout.flush();
        cin >> x;
        a[i + 1] = (x ? a[i] : ~a[i]);
    }
    auto check = [&](int l, int r) {
        int x;
        cout << "? " << l << ' ' << r << '\n';
        cout.flush();
        cin >> x;
        if (x) return a[l] == a[r];
        return a[l] != a[r];
    };
    int l = 1, r = n, mid;
    while (r - l + 1 > 2) {
        mid = (l + r) >> 1;
        if (check(mid, l)) l = mid + 1;
        else r = mid;
    }
    int x1, x2;
    int ll = l, rr = l - 1;
    if (!rr) rr = n;
    cout << "? " << ll << ' ' << rr << '\n';
    cout.flush();
    cin >> x1;
    cout << "? " << rr << ' ' << ll << '\n';
    cout.flush();
    cin >> x2;
    cout << "! " << (x1 == x2 ? r : l) << '\n';
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}