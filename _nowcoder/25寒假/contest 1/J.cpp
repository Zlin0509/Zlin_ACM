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

inline void Zlin()
{
    int n;
    cin >> n;
    vi a(n);
    unordered_map<int, int> M;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        M[a[i]]++;
    }
    ll ans = 0;
    for (auto it : a)
    {
        for (int i = 1; i <= sqrt(it); i++)
        {
            if (it % i)
                continue;
            int y = i xor it;
            if (gcd(y, it) == i)
                ans += M[y];
            if (it / i != i)
            {
                y = (it / i) xor it;
                if (gcd(y, it) == it / i)
                    ans += M[y];
            }
        }
    }
    cout << ans / 2 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
