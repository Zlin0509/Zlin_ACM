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

inline void Zlin()
{
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0, tag = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == tag)
            continue;
        ++ans;
        tag = a[i];
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
