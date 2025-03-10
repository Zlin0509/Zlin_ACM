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

constexpr ll mo = 998244353;

inline ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return res;
}

ll fac[300010];

inline void Zlin()
{
    for (int i = 1; i <= 3e5; i++)
        fac[i] = qpow(i, mo - 2);
    int n, m;
    string s;
    cin >> n >> m >> s;
    bool check = s[0] != '?';
    ll res = 1;
    for (int i = 1; i < s.length(); i++)
        if (s[i] == '?')
            res = res * i % mo;
    cout << (check ? res : 0) << endl;
    while (m--)
    {
        int x;
        char c;
        cin >> x >> c;
        --x;
        swap(s[x], c);
        check = s[0] != '?';
        if (x)
        {
            if (c == '?' && s[x] != '?')
                res = res * fac[x] % mo;
            if (c != '?' && s[x] == '?')
                res = res * x % mo;
        }
        cout << (check ? res : 0) << endl;
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
