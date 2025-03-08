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
    ll sum = 0;
    ll n, p;
    cin >> n >> p;
    vll a(n);
    for (ll& it : a)
    {
        cin >> it;
        sum = (sum + it) % 2;
    }
    if (p & 1)
        cout << (sum & 1 ? "GOOD" : "BAD") << endl;
    else
    {
        sum = 0;
        ll cnt = 0;
        for (ll& it : a)
        {
            cnt = (cnt + it / 2 % 2) % 2;
            sum = (sum + it % p) % 2;
        }
        if (sum & 1)
            cout << (cnt & 1 ? "BAD" : "GOOD") << endl;
        else
            cout << (cnt & 1 ? "GOOD" : "BAD") << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
