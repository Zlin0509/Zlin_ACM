//
// Created by 27682 on 2025/4/16.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr ll mo = 998244353;
const int N = 1e7; // 定义最大 N 值
ll fact[N + 1], inv[N + 1];

// 快速幂求 a^b % mo
ll qpw(ll a, ll b) {
    long long res = 1;
    while (b) {
        if (b % 2 == 1) res = res * a % mo;
        a = a * a % mo;
        b /= 2;
    }
    return res;
}

inline void Zlin() {
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
