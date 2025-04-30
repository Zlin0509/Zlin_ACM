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

inline void Zlin()
{
    int n;
    cin >> n;
    vector<pii> a(n);
    for (auto& [l,r] : a)
        cin >> l >> r;
    auto [x,y] = a[0];
    int tag = -1;
    for (auto [l,r] : a)
    {
        if (r < x)
        {
            tag = x;
            break;
        }
        if (l > y)
        {
            tag = y;
            break;
        }
        x = max(x, l);
        y = min(y, r);
    }
    if (tag == -1) tag = x;
    vi ans;
    for (auto [l,r] : a)
    {
        if (l > x)
            x = l;
        if (r < x)
            x = r;
        ans.emplace_back(x);
    }
    for (int i = n - 2; i >= 0; i--)
        if (ans[i + 1] < ans[i])
            ans[i] = max(ans[i + 1], a[i].first);
    for (int it : ans)
        cout << it << ' ';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
