//
// Created by Zlin on 2024/12/10.
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

const int N = 1e5 + 5;
int n, a[N];

const int NN = 4e5 + 200;
int tag[NN];

void dd() {
    tag[1] = 1;
    vi primes;
    for (int i = 2; i < NN; i++) {
        if (!tag[i]) primes.push_back(i);
        for (int j = 0; j < primes.size() && primes[j]*i < NN; j++) {
            tag[i * primes[j]] = primes[j];
            if (i % primes[j] == 0) break;
        }
    }
}

inline void Zlin() {
    cin >> n;
    int x = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        if (tag[a[i]] || a[i] == 2) continue;
        if (!x) x = a[i];
        else {
            cout << -1 << '\n';
            return;
        }
    }
    if (!x) {
        cout << 2 << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == x) continue;
        if ((a[i] & 1) && a[i] - tag[a[i]] < 2 * x) {
            cout << -1 << '\n';
            return;
        }
        if (!(a[i] & 1) && a[i] < 2 * x) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    dd();
//    for (int i = 1; i <= 100; i++) cout << tag[i] << ' ';
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}