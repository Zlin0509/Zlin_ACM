//
// Created by Zlin on 2025/1/23.
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
    bool tag = true;
    while (n--)
    {
        int c;
        cin >> c;
        if (c == 1 || c == 2 || c == 3 || c == 5 || c == 6 || c == 6)
            continue;
        tag = false;
    }
    cout << (tag ? "YES" : "NO") << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
