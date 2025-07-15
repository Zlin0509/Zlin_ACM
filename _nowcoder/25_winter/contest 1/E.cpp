//
// Created by Zlin on 2025/1/21.
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

int n;
vi a;
vll sum;

inline void Zlin()
{
    cin >> n;
    a.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    ll suml = 0, sumr = 0;
    ll ans = 0;
    int xx = n / 2;
    int ltag = a[xx / 2], rtag = a[xx / 2 + xx];
    if (ltag != rtag)
    {
        for (int i = 0; i < xx; i++)
            suml += abs(a[i] - ltag);
        for (int i = xx; i < n; i++)
            sumr += abs(a[i] - rtag);
        ans += suml + sumr;
    }
    else
    {
        rtag++;
        for (int i = 0; i < xx; i++)
            suml += abs(a[i] - ltag);
        for (int i = xx; i < n; i++)
            sumr += abs(a[i] - rtag);
        ans = suml + sumr;

        suml = sumr = 0;
        rtag--;
        ltag--;
        for (int i = 0; i < xx; i++)
            suml += abs(a[i] - ltag);
        for (int i = xx; i < n; i++)
            sumr += abs(a[i] - rtag);
        ans = min(ans, suml + sumr);
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
