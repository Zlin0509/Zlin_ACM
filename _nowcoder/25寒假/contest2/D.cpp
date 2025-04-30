//
// Created by Zlin on 2025/1/23.
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
string s;
map<char, int> last, fr;

inline void Zlin()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        last[s[i]] = i;
    for (int i = n - 1; i >= 0; i--)
        fr[s[i]] = i;
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (last[s[i]] > i)
            ans = max(ans, i + 1);
    for (int i = n - 1; i >= 0; i--)
        if (fr[s[i]] < i)
            ans = max(ans, n - i);
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
