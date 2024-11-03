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

ll a, b, x;

inline void Zlin() {
    cin >> a >> b >> x;
    ll z = gcd(a, b);
    if (a < x && b < x) {
        cout << "NO" << '\n';
        return;
    }
    if ((a - x) % z == 0 || (b - x) % z == 0) {
        cout << "YES" << '\n';
    } else cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}