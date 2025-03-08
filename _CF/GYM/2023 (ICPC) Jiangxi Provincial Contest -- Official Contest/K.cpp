//
// Created by Zlin on 2025/3/8.
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
    vll have;
    for (int i = 1; i < n; i++)
        have.push_back(a[i - 1] - a[i]);
    sort(have.begin(), have.end(), greater<ll>());
    vll sum(n);
    for (int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + have[i - 1];
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (x == 1)
            cout << sum[n - 1] - sum[y - 1] << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
