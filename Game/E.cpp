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

constexpr ll mo = 1e9 + 7;

inline void Zlin()
{
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        a[x] = i;
    }
    set<int> now;
    now.insert(a[0]);
    ll ans = 1;
    for (int i = 1; i < n; i++)
    {
        int id = a[i];
        int l = *now.begin(), r = *prev(now.end());
        if (l < id && id < r)
            ans = ans * (r - l + 1 - now.size()) % mo;
        now.insert(id);
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
