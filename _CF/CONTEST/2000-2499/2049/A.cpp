//
// Created by Zlin on 2024/12/20.
//

#include "bits/stdc++.h"

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
    bool check1 = false;
    int l = n, r = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i]) check1 = true, l = min(l, i), r = max(r, i);
    }
    if (!check1)
    {
        cout << 0 << '\n';
        return;
    }
    for (int i = l; i <= r; i++)
        if (!a[i])
        {
            cout << 2 << '\n';
            return;
        }
    cout << 1 << '\n';
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
