//
// Created by Zlin on 2024/10/23.
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

int N = 1000;

inline void Zlin() {
    int n = rand() % 10000;
    cout << n << " ";
    for (int i = 1; i <= n; i++)
        cout << rand() % 10000 << ' ';
}

int main() {
    srand(time(0));
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}