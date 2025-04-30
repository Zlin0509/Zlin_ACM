//
// Created by Zlin on 2025/2/27.
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
    string s;
    cin >> n >> s;
    s = ' ' + s;
    vi sum(n + 1);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + (s[i] == '0' ? 1 : -3);
    ll ans = 0;
    unordered_map<int, int> cnt;
    for (int i = 0, now = 0, tag = 0; i <= n; i++)
    {
        ans += cnt[sum[i] + 1];
        int r = sum[i] - 2;
        while (tag < r)
            now += cnt[++tag];
        while (tag > r)
            now -= cnt[tag--];
        ans += now;
        cnt[sum[i]]++;
        if (sum[i] <= tag)
            ++now;
    }
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
