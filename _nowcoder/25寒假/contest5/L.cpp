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

constexpr int N = 1e6 + 10;

int vis[N];

int n;
unordered_set<int> l, r;

inline void Zlin()
{
    int n;
    cin >> n;
    int k = n / 4;
    vector<pair<pii, int>> res;
    for (int i = 1; i <= n; i++)
    {
        if (i & 1 || i + 2 > n)
            l.insert(i);
        else
        {
            res.push_back({{i, i + 1}, i + 2});
            i += 2;
        }
    }


    cout << k << endl;
    for (auto it : res)
        cout << it.first.first << " " << it.first.second << " " << it.second << endl;
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
