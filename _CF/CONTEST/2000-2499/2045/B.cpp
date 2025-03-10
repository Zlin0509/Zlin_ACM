//
// Created by 27682 on 2025/2/24.
//

#include "bits/stdc++.h"

#define endl '\n'
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
    ll n, d, s;
    cin >> n >> d >> s;
    n /= s, d /= s;
    if (d == 0)
    {
        cout << s << endl;
        return;
    }
    if (n <= d + 1)
    {
        cout << n * s << endl;
        return;
    }
    n = min(n, d * 2ll);
    // if (n % 2 == 0)
    // {
    //     cout << n * s << endl;
    //     return;
    // }
    for (ll i = 2; i <= 1e6; i++)
        if (n % i == 0 && n - n / i <= d)
        {
            cout << n * s << endl;
            return;
        }
    cout << (n - 1) * s << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
