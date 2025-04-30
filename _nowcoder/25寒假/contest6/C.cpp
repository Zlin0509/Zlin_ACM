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

const int INF = 1e6;

vi su;
vi used(INF);

void dd()
{
    for (int i = 2; i < INF; i++)
    {
        if (used[i])
            continue;
        su.push_back(i);
        for (int j = 1; j * i < INF; j++)
            used[i * j] = i;
    }
}

ll check(ll x)
{
    ll res = 0;
    for (auto it : su)
        if (x / it - it + 1 >= 2)
            res += (x / it - it + 1) / 2;
    return res + 1;
}

inline void Zlin()
{
    ll n;
    cin >> n;
    ll l = 2, r = 1e18, mid;
    while (l < r)
    {
        mid = l + r >> 1;
        if (check(mid) >= n)
            r = mid;
        else
            l = mid + 1;
    }
    // for (int i = 1; i <= 20; i++)
    //     cout << i << ' '
    //         << check(i) << endl;
    cout << check(18) << endl;
    cout << l << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    dd();
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
