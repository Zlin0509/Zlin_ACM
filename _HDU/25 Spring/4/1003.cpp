//
// Created by 27682 on 2025/3/28.
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


ll k, b, c, v;
int zz;

inline ll dfs(int i, ll pre) {
    ll res = 0;
    if (pre ^ c < 1ll << zz) {

        return res;
    }
    if (pre ^ c >= 1ll << zz + 1) {
        return 0;
    }
    return res;
}

inline void Zlin() {
    cin >> k >> b >> c >> v;
    cout << dfs(63, 0) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
