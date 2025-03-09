//
// Created by Zlin on 2025/3/9.
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
    int n;
    cin >> n;
    vector<pii> a(n);
    for (auto& it : a)
        cin >> it.first >> it.second;
    int tag = max(a[0].first, a[0].second);
    for (int i = 1; i < n; i++)
    {
        auto [x,y] = a[i];
        if (max(x, y) <= tag)
            tag = max(x, y);
        else if (min(x, y) <= tag)
            tag = min(x, y);
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
