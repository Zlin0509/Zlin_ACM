//
// Created by Zlin on 2025/3/3.
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
    ll n, k;
    cin >> n >> k;
    if (n == k)
    {
        cout << "YES" << endl;
        cout << 1 << endl << 1 << endl;
    }
    else if (n / k >= 2)
    {
        cout << "YES" << endl;
        if (n / (n / k) == k)
            cout << 1 << endl << n / k << endl;
        else
            cout << 2 << endl << n - k + 1 << ' ' << 1 << endl;
    }
    else if (n / 2 + n % 2 == k)
    {
        cout << "YES" << endl;
        cout << 2 << endl << 2 << ' ' << 1 << endl;
    }
    else cout << "NO" << endl;
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
