//
// Created by 27682 on 2025/4/11.
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

inline void Zlin()
{
    ll k;
    cin >> k;
    vll a(3);
    for (ll &it: a) cin >> it;
    vll have;
    have.push_back(a[0] + a[1] + a[2]);
    for (int i = 0; i < 3; i++) {
        have.push_back(a[i]);
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            have.push_back(a[i] + a[j]);
        }
    }
    have.push_back(0);
    sort(have.begin(), have.end());
    while (have.back() > k) {
        have.pop_back();
    }
    cout << k - have.back() << endl;
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