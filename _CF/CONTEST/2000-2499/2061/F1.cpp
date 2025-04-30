//
// Created by Zlin on 2025/1/27.
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

int n, ans;
string s, t;


inline void Zlin()
{
    cin >> s >> t;
    s = ' ' + s;
    t = ' ' + t;
    ans = 0;
    n = s.length();
    for (int i = 1; i <= n; i++)
        if (s[i] != t[i])
        {
            if (i > 1 && s[i] == s[i - 1] && t[i] != t[i - 1])
                return cout << "-1\n", void();
            int j = i, k = i, cnt = 0, tmp = 0;
            while (j < n && t[j + 1] == t[i]) ++j;
            while (k < n && cnt < j - i + 1)
            {
                cnt += s[++k] == t[i];
                if (s[k] == t[i] && s[k - 1] != t[i]) ++tmp;
            }
            if (cnt < j - i + 1) return cout << "-1\n", void();
            if (k < n && s[k + 1] == t[i]) return cout << "-1\n", void();
            ans += tmp;
            for (int w = i; w <= j; w++)
                s[w] = t[i];
            for (int w = j + 1; w <= k; w++)
                s[w] = (t[i] == '1' ? '0' : '1');
        }
    cout << ans << "\n";
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
