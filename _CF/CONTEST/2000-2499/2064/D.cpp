//
// Created by Zlin on 2025/2/16.
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

constexpr ll mo = (1ll << 32) - 1;


inline void Zlin()
{
    int n, q;
    cin >> n >> q;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[n - i + 1];

    vll Q(n + 1);
    Q[0] = mo;
    for (int i = 1; i <= n; i++)
        Q[i] ^= Q[i - 1];


    while (q--)
    {
        int x;
        cin >> x;
    }
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
