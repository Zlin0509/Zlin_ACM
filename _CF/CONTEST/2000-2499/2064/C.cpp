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
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vll l(n), r(n);
    l[0] = max(0, a[0]);
    r[n - 1] = max(0, -a[n - 1]);
    for (int i = 1; i < n; i++)
        l[i] = l[i - 1] + max(0, a[i]);
    for (int i = n - 2; i >= 0; i--)
        r[i] = r[i + 1] + max(0, -a[i]);
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, l[i] + r[i]);
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
