//
// Created by 27682 on 2025/3/11.
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

inline void Zlin()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    vll f(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1')
            f[i] = f[max(0, i - 3)] + i;
        else
            f[i] = f[i - 1];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += f[i];
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
