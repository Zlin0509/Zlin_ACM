//
// Created by Zlin on 2025/1/13.
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

constexpr int N = 1e5 + 5;

int n, k;
vi h(N);
vector<vi> mx(N, vi(22, 0)), mm(N, vi(22, 0));

void d1()
{
    for (int i = 0; i < n; i++)
        mx[i][0] = mm[i][0] = h[i];
    int t = log(n) / log(2) + 1;
    for (int j = 1; j < t; j++)
        for (int i = 0; i <= n - (1 << j); i++)
        {
            mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
            mm[i][j] = min(mm[i][j - 1], mm[i + (1 << (j - 1))][j - 1]);
        }
}

int query(int l, int r)
{
    int k = log(r - l + 1) / log(2);
    return max(mx[l][k], mx[r - (1 << k) + 1][k]) - min(mm[l][k], mm[r - (1 << k) + 1][k]);
}

inline void Zlin()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> h[i];
    d1();
    int len = 0;
    vector<pii> ans;
    for (int i = 0, l, r, mid; i < n; i++)
    {
        l = i, r = n - 1;
        while (l < r)
        {
            mid = (l + r + 1) >> 1;
            if (query(i, mid) <= k) l = mid;
            else r = mid - 1;
        }
        len = max(len, l - i + 1);
    }
    for (int i = 0; i <= n - len; i++)
        if (query(i, i + len - 1) <= k)
            ans.push_back({i, i + len - 1});
    cout << len << ' ' << ans.size() << '\n';
    for (auto [l,r] : ans)
        cout << l + 1 << ' ' << r + 1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
