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
    int n;
    cin >> n;
    vi a(n);
    vi cnt(n + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i], ++cnt[a[i]];
    int l = 0, r = 0;
    int ll = 0, rr = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnt[a[i]] == 1)
        {
            if (!l)
                l = i + 1, r = i + 1;
            else
                r = i + 1;

            if (rr - ll <= r - l)
                rr = r, ll = l;
        }
        else
            l = r = 0;
    }
    if (ll)
        cout << ll << ' ' << rr;
    else
        cout << 0;
    cout << endl;
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
