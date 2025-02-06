//
// Created by Zlin on 2025/2/6.
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
    int n, m;
    string x, y;
    cin >> n >> m;
    cin >> x >> y;
    if (n > m)
        swap(x, y), swap(n, m);
    map<char, int> cntl, cntr;
    for (auto it : x)
        cntl[it]++;
    for (auto it : y)
        cntr[it]++;
    ll ans = 0;
    ll cnt = m - n;
    for (char it = 'a'; it <= 'z'; it++)
    {
        if (cntr[it] <= cntl[it])
            continue;
        int have = cntr[it] - cntl[it];
        while (have >= 2 && cnt >= 2)
            cnt -= 2, cntr[it] -= 2, have -= 2;
    }
    ans = cnt / 2;
    for (char it = 'a'; it <= 'z'; it++)
    {
        while (cntl[it])
        {
            if (cntr[it])
                --cntr[it];
            else
                ++ans;
            --cntl[it];
        }
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
