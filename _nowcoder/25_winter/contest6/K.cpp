//
// Created by Zlin on 2025/2/11.
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
    ll x, y;
    cin >> x >> y;
    if (!(y & 1))
    {
        cout << "NO\n";
        return;
    }
    if (y == 1)
    {
        cout << (x & 1 ? "NO" : "YES") << endl;
        return;
    }
    ll z = y / 2;
    if (abs(z - x) & 1)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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
