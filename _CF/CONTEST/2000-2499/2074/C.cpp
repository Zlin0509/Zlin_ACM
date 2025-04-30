//
// Created by 27682 on 2025/3/11.
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
    int n;
    cin >> n;
    int cnt0 = 0, cnt1 = 0;
    int k = 0;
    while (1 << k <= n)
    {
        n & 1 << k ? cnt1++ : cnt0++;
        ++k;
    }
    if (!cnt1 || !cnt0 || cnt1 == 1)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; 1 << i + 1 <= n; i++)
    {
        if (!(n & 1 << i) && n & 1 << i + 1)
        {
            int y = n - (1 << i);
            cout << y << endl;
            return;
        }
    }
    cout << -1 << endl;
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
