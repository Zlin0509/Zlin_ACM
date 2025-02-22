//
// Created by Zlin on 2025/2/3.
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

void pre(vi& a, vi& b, vll& sl, vll& sr)
{
    sl.push_back(0), sr.push_back(0);
    int l = 0, r = a.size() - 1;
    while (l < r)
    {
        ll tag = a[r--] - a[l++];
        tag += sl.back();
        sl.push_back(tag);
    }
    l = 0, r = b.size() - 1;
    while (l < r)
    {
        ll tag = b[r--] - b[l++];
        tag += sr.back();
        sr.push_back(tag);
    }
}

inline void Zlin()
{
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vll sl, sr;
    auto cal = [&](int x)
    {
        int l = x, r = min(n - x * 2, (m - x) / 2);
        ll res = sl[l] + sr[r];
        return res;
    };
    pre(a, b, sl, sr);
    ll ans = 0;
    int l = 0, r = min(n / 2, m);
    while (l < r)
    {
        int ml = l + (r - l) / 3, mr = r - (r - l) / 3;
        ll resl = cal(ml);
        ll resr = cal(mr);
        ans = max({ans, resl, resr});
        if (resl < resr)
            l = ml + 1;
        else
            r = mr - 1;
    }
    ans = max(ans, cal(l));
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
