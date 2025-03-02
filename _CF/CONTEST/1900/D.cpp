//
// Created by Zlin on 2025/3/2.
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

constexpr int N = 1e5 + 5;

vector su(N, vi());

inline void dd()
{
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            su[j].push_back(i);
    for (int i = 1; i < N; i++)
        reverse(su[i].begin(), su[i].end());
}

inline void Zlin()
{
    int n;
    cin >> n;
    vi a(n);
    for (int& it : a)
        cin >> it;
    sort(a.begin(), a.end());
    ll ans = 0, sum = 0;
    vi f(N), g(N);
    for (int it : a)
    {
        ans += sum;
        for (int x : su[it])
        {
            f[x] = g[x];
            for (int y : su[it / x])
                if (y != 1)
                    f[x] -= f[x * y];
            sum += 1ll * x * f[x];
            g[x]++;
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    dd();
    while (ttt--) Zlin();
    return 0;
}
