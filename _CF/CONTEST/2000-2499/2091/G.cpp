//
// Created by 27682 on 2025/5/7.
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

constexpr int N = 1e6 + 10;

bitset<N> f, g, z;

inline void Zlin() {
    int s, k;
    cin >> s >> k;
    if (s >= k * k) {
        cout << (s % k ? max(k - 2, 1) : k) << endl;
        return;
    }
    z.reset(), f.reset(), g.reset();
    for (int i = 0; i <= s; i++) {
        z[i] = true;
        if (i % k == 0) f[i] = true;
    }
    for (int i = k - 1; i; i--) {
        if (f[s]) {
            cout << i + 1 << endl;
            return;
        }
        g.reset();
        if (k - i & 1) { // 往左走
            for (int j = 1; j * i <= s; j++) {
                g |= f >> j * i;
            }
        } else { // 往右走
            for (int j = 1; j * i <= s; j++) {
                g |= f << j * i;
            }
        }
        f = g & z;
    }
    cout << 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}