//
// Created by Zlin on 2025/2/18.
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
    string s;
    cin >> s;
    int n = s.length();
    unordered_map<char, vi> tag;
    for (int i = 0; i < n; i++)
        tag[s[i]].push_back(i);
    int l = n, r = 0;
    for (int i = 0, ll, rr; i < n; i++)
    {
        char c = s[i];
        ll = i;
        rr = tag[c].back();
        tag[c].pop_back();
        if (rr <= i)
            continue;
        rr = n - rr - 1;
        if (ll == rr)
            continue;
        l = min(l, ll);
        r = max(r, rr);
    }
    cout << (l == n ? 0 : r - l + 1) << endl;
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
