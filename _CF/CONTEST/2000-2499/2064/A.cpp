//
// Created by Zlin on 2025/2/16.
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
    string s;
    int n;
    cin >> n >> s;
    bool tag = false;
    int ans = 0;
    for (auto it : s)
    {
        if (it == '0')
        {
            if (tag)
            {
                ans += 2;
                tag = 0;
            }
        }
        else
            tag = 1;
    }
    if (tag)
        ++ans;
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
