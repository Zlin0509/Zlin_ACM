//
// Created by 27682 on 2025/7/1.
//
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi primes;
vector<bool> isPrime;

inline void init(int n) {
    isPrime.assign(n, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) primes.push_back(i);
        for (int j: primes) {
            if (i * j >= n) break;
            isPrime[i * j] = false;
            if (i % j == 0) break;
        }
    }
}

inline void Zlin() {
    init(1e7);
    int n;
    cin >> n;
    for (int i = 1; i < 1e4; i++) {
        if (!isPrime[i * n + 1]) {
            cout << i << endl;
            return;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
