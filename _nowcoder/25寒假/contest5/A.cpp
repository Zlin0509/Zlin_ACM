//
// Created by Zlin on 2025/2/8.
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
    ll n;
    char x;
    cin >> n >> x;
    if (x == '*')
    {
        cout << n << ' ' << 1 << endl;
    }
    else if (x == '+')
    {
        cout << n - 1 << ' ' << 1 << endl;
    }
    else
    {
        cout << n + 1 << ' ' << 1 << endl;
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
