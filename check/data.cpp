//
// Created by Zlin on 2025/2/7.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline void Zlin() {
    int n = rng() % 10 + 1, k = rng() % 10 + 1, q = rng() % 10 + 1;
    string s;
    for (int i = 1; i <= n; i++) {
        char c = 'a' + rng() % 26;
        s += c;
    }
    cout << n << ' ' << k << ' ' << q << endl;
    cout << s << endl;
    while (q--) {
        int l = rng() % n + 1, r = rng() % n + 1;
        if (l > r) swap(l, r);
        cout << l << ' ' << r << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    srand(time(0));
    while (ttt--) Zlin();
    return 0;
}
