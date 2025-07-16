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

ll n, ans;
string s;
string x = "uwawauwa";

inline void Zlin()
{
    cin >> n >> s;
    ans = 0;
    ll cnt = 0;
    int len = x.length();
    if (n < len + 2)
    {
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i < n; i++)
        if (s[i] == 'u')
            ++cnt;
    for (int i = n - 1; i >= n - len; i--)
        if (s[i] == 'u')
            --cnt;
    for (int i = n - len - 1; i >= 0; i--)
    {
        if (s[i] == 'u')
            --cnt;
        bool check = true;
        for (int j = 0; j < len; j++)
            if (s[i + 1 + j] != x[j])
            {
                check = false;
                break;
            }
        if (check)
            ans += cnt;
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
