//
// Created by Zlin on 2024/10/14.
//

#include "bits/stdc++.h"
#include "random"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1e3;
const ll M = 2e3;

int n;
ll m;

inline void Zlin() {
    n = random() % N, m = random() % M;
    vi a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        a[i] = random() % N;
        b[i] = random() % 2 + 1;
        c[i] = random() % N;
    }
    cout << n << ' ' << m << '\n';
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ' << b[i] << ' ' << c[i] << '\n';
}

int main() {
    srand(time(0));
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
}