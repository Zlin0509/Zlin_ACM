//
// Created by 27682 on 2025/3/20.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline void Zlin()
{
    int n;
    cin >> n;
    vi a(n);
    ll sum = 0;
    for (int& it : a) cin >> it, sum += it;
    if (sum % n)
    {
        cout << "No" << endl;
        return;
    }
    sum /= n;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
