//
// Created by 27682 on 2025/4/11.
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

constexpr ll mo = 1e9 + 7;
constexpr int N = 1e6;

ll fac1[N + 10], fac2[N + 10], f[2][N + 10];
string s;;

inline void Zlin() {
    getline(cin, s);
    cout << s << endl;
    for (auto it: s) cout << it;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    // cin.ignore();
    getline(cin, s);
    while (ttt--) Zlin();
    return 0;
}
