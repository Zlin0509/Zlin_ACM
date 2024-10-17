//
// Created by Zlin on 2024/10/17.
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

const ll N = 1e6;

inline void Zlin() {
    ll l, r;
    r = random() % N;
    l = random() % r;
    cout << l << ' ' << r;
}

int main() {
    srand(time(0));
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}