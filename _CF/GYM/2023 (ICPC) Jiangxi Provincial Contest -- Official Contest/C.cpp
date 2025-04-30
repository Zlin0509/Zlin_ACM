//
// Created by Zlin on 2025/3/8.
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

inline void Zlin()
{
    ll n, p;
    cin >> n >> p;
    vll a(n);
    ll ans = 0;
    for (ll& it : a)
    {
        cin >> it;
        ans ^= it;
    }
    cout << (ans ? "GOOD" : "BAD") << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
