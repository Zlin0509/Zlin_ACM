//
// Created by 27682 on 2025/6/8.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

bool canExplode(const vector<long long> &a) {
    int n = a.size();

    long long a1 = a[0];
    long long an = a[n - 1];

    long long denominator = n * n - 1;

    long long y = n * a1 - an;
    long long x = n * an - a1;
    if (y % denominator || x % denominator) return false;
    x /= denominator;
    y /= denominator;
    if (x < 0 || y < 0) return false;
    for (int i = 0; i < n; ++i) {
        long long expected = x * (i + 1) + y * (n - i);
        if (a[i] != expected) return false;
    }
    return true;
}

inline void Zlin() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << (canExplode(a) ? "YES" : "NO") << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
