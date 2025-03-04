//
// Created by 27682 on 2025/3/3.
//

#include "bits/stdc++.h"

#define endl '\n'
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr ll mo = 998244353;
constexpr int N = 1e6 + 10;

int n;
ll ans[N], a[N];

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    cout << ans[n] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--)
        Zlin();
    return 0;
}