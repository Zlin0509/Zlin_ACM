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

vector<int> generate_shuffled_permutation(int n) {
    vector<int> a(n);
    iota(a.begin(), a.end(), 1); // 生成 [1, 2, ..., n]
    shuffle(a.begin(), a.end(), rng);
    return a;
}

inline void Zlin() {
    int n = rng() % 10 + 1;
    vi a(n), b(n);
    a = generate_shuffled_permutation(n);
    b = generate_shuffled_permutation(n);
    for (int i = 1; i <= 100; i++) {
        int k = rng() % n;
        swap(a[k], b[k]);
    }
    cout << n << endl;
    for (int it: a) cout << it << ' ';
    cout << endl;
    for (int it: b) cout << it << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << 1 << endl;
    int ttt = 1;
    srand(time(0));
    while (ttt--) Zlin();
    return 0;
}
