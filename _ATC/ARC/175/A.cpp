//
// Created by 27682 on 2025/3/10.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr ll mo = 998244353;

inline void Zlin()
{
    int n;
    cin >> n;
    vi a(n);
    for (int& it : a)
        cin >> it, --it;
    string s;
    cin >> s;
    ll ans1 = (s[a[n - 1]] == '?' ? 2 : 1), ans2 = (s[a[n - 1]] == '?' ? 2 : 1);
    vi used(n);
    for (int i = 0; i < n - 1; i++)
    {
        int it = a[i], l = it - 1;
        if (l == -1) l = n - 1;
        if (s[it] == '?')
            ans1 *= used[l] ? 2 : 1;
        if (s[it] == 'L')
            ans1 *= used[l] ? 1 : 0;
        ans1 %= mo;
        used[it] = 1;
    }
    used.assign(n, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int it = a[i], r = it + 1;
        if (r == n) r = 0;
        if (s[it] == '?')
            ans2 *= used[r] ? 2 : 1;
        if (s[it] == 'R')
            ans2 *= used[r] ? 1 : 0;
        ans2 %= mo;
        used[it] = 1;
    }
    cout << (ans1 + ans2) % mo << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
