//
// Created by Zlin on 2025/1/15.
//

#include "bits/stdc++.h"

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
    int n, m;
    cin >> n >> m;
    vi a(n + m), cnt(2);
    vi ans1(2, 0), ans2(2, 0);
    a[0] = 0, cnt[0] = 1;
    for (int i = 1, tag; i < n + m; i++)
    {
        if (i & 1)
        {
            tag = a[i - 1] ^ 1;
            if (cnt[tag] < (tag ? n : m)) a[i] = tag, ++cnt[tag];
            else a[i] = tag ^ 1, ++cnt[tag ^ 1];
        }
        else
        {
            tag = a[i - 1];
            if (cnt[tag] < (tag ? n : m)) a[i] = tag, ++cnt[tag];
            else a[i] = tag ^ 1, ++cnt[tag ^ 1];
        }
    }
    // for (int i = 0; i < n + m; i++) cout << a[i] << ' ';
    // cout << '\n';
    for (int i = 1; i < n + m; i++)
    {
        if (a[i] == a[i - 1])++ans1[0];
        else ++ans1[1];
    }
    a[0] = 1, cnt[1] = 1,cnt[0] = 0;
    for (int i = 1, tag; i < n + m; i++)
    {
        if (i & 1)
        {
            tag = a[i - 1] ^ 1;
            if (cnt[tag] < (tag ? n : m)) a[i] = tag, ++cnt[tag];
            else a[i] = tag ^ 1, ++cnt[tag ^ 1];
        }
        else
        {
            tag = a[i - 1];
            if (cnt[tag] < (tag ? n : m)) a[i] = tag, ++cnt[tag];
            else a[i] = tag ^ 1, ++cnt[tag ^ 1];
        }
    }
    for (int i = 1; i < n + m; i++)
    {
        if (a[i] == a[i - 1]) ++ans2[0];
        else ++ans2[1];
    }
    if (ans1[0] < ans2[0])
    {
        cout << ans2[0] << ' ' << ans2[1] << '\n';
    }
    else
    {
        cout << ans1[0] << ' ' << ans1[1] << '\n';
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
