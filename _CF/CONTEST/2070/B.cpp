//
// Created by Zlin on 2025/2/27.
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
    int n, x;
    ll k;
    cin >> n >> x >> k;
    string s;
    cin >> s;
    ll ans = 0;
    for (auto it : s)
    {
        if (!x)
            break;
        if (it == 'R')
            ++x;
        else
            --x;
        --k;
    }
    if (!x)
    {
        ++ans;
        ll tag = 0;
        for (auto it : s)
        {
            ++tag;
            if (it == 'R')
                ++x;
            else
                --x;
            if (!x)
                break;
        }
        if (!x)
            ans += k / tag;
    }
    cout << ans << endl;
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
