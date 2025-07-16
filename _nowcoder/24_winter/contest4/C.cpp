//
// Created by Zlin on 2025/2/6.
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
constexpr int N = 2e5 + 10;

int n;
string s;
ll dpl[N][2][3], dpr[N][2][3];

inline void Zlin()
{
    cin >> n >> s;
    s = ' ' + s;
    if (n == 1)
    {
        cout << (s[1] == '?' ? 2 : 1) << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 2; j++)
            for (int q = 0; q < 3; q++)
                dpl[i][j][q] = dpr[i][j][q] = 0;

    if (s[1] == '1' || s[1] == '?')
        dpl[1][1][2] = 1;
    if (s[1] == '0' || s[1] == '?')
        dpl[1][0][0] = 1;
    if (s[n] == '1' || s[n] == '?')
        dpr[n][1][2] = 1;
    if (s[n] == '0' || s[n] == '?')
        dpr[n][0][0] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (s[i] == '0' || s[i] == '?')
        {
            dpl[i][0][0] = (dpl[i - 1][0][0] + dpl[i - 1][1][1]) % mo;
            dpl[i][0][1] = (dpl[i - 1][0][1] + dpl[i - 1][1][2]) % mo;
        }

        if (s[i] == '1' || s[i] == '?')
        {
            dpl[i][1][1] = (dpl[i - 1][1][1] + dpl[i - 1][0][0]) % mo;
            dpl[i][1][2] = (dpl[i - 1][1][2] + dpl[i - 1][0][1]) % mo;
        }
    }
    for (int i = n - 1; i >= 1; i--)
    {
        if (s[i] == '0' || s[i] == '?')
        {
            dpr[i][0][0] = (dpr[i + 1][0][0] + dpr[i + 1][1][1]) % mo;
            dpr[i][0][1] = (dpr[i + 1][0][1] + dpr[i + 1][1][2]) % mo;
        }

        if (s[i] == '1' || s[i] == '?')
        {
            dpr[i][1][1] = (dpr[i + 1][1][1] + dpr[i + 1][0][0]) % mo;
            dpr[i][1][2] = (dpr[i + 1][1][2] + dpr[i + 1][0][1]) % mo;
        }
    }

    ll ans = 0;
    if (s[1] == '0' || s[1] == '?')
    {
        ans = (ans + dpr[2][1][2]) % mo;
        ans = (ans + dpr[2][0][1]) % mo;
    }
    if (s[1] == '1' || s[1] == '?')
    {
        ans = (ans + dpr[2][0][0]) % mo;
        ans = (ans + dpr[2][1][1]) % mo;
    }
    if (s[n] == '1' || s[n] == '?')
    {
        ans = (ans + dpl[n - 1][0][0]) % mo;
        ans = (ans + dpl[n - 1][1][1]) % mo;
    }
    if (s[n] == '0' || s[n] == '?')
    {
        ans = (ans + dpl[n - 1][1][2]) % mo;
        ans = (ans + dpl[n - 1][0][1]) % mo;
    }

    for (int i = 2; i <= n - 1; i++)
    {
        ll tag = 0;
        if (s[i] == '0' || s[i] == '?')
        {
            tag = (tag + dpl[i - 1][1][2] * dpr[i + 1][1][2]) % mo;
            tag = (tag + dpl[i - 1][1][1] * dpr[i + 1][1][1]) % mo;

            tag = (tag + dpl[i - 1][0][1] * dpr[i + 1][1][2]) % mo;
            tag = (tag + dpl[i - 1][0][0] * dpr[i + 1][1][1]) % mo;

            tag = (tag + dpl[i - 1][0][1] * dpr[i + 1][0][1]) % mo;
            tag = (tag + dpl[i - 1][0][0] * dpr[i + 1][0][0]) % mo;

            tag = (tag + dpl[i - 1][1][2] * dpr[i + 1][0][1]) % mo;
            tag = (tag + dpl[i - 1][1][1] * dpr[i + 1][0][0]) % mo;
        }
        if (s[i] == '1' || s[i] == '?')
        {
            tag = (tag + dpl[i - 1][0][1] * dpr[i + 1][0][1]) % mo;
            tag = (tag + dpl[i - 1][0][0] * dpr[i + 1][0][0]) % mo;

            tag = (tag + dpl[i - 1][1][2] * dpr[i + 1][0][1]) % mo;
            tag = (tag + dpl[i - 1][1][1] * dpr[i + 1][0][0]) % mo;

            tag = (tag + dpl[i - 1][1][1] * dpr[i + 1][1][1]) % mo;
            tag = (tag + dpl[i - 1][1][2] * dpr[i + 1][1][2]) % mo;

            tag = (tag + dpl[i - 1][0][1] * dpr[i + 1][1][2]) % mo;
            tag = (tag + dpl[i - 1][0][0] * dpr[i + 1][1][1]) % mo;
        }

        ans = (ans + tag) % mo;
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
