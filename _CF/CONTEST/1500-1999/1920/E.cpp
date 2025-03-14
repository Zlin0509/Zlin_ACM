//
// Created by 27682 on 2025/3/12.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr ll mo = 998244353;

inline void Zlin()
{
    int n, k;
    cin >> n >> k;
    vector f(n + 1, vll(k + 1, 0)), g(n + 1, vll(k + 1, 0));
    f[0][0] = 1;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
