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
    vector<char> a(n + 1);
    vi l, r;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] == '>' ? l.push_back(i) : r.push_back(i);
    }

    int tl, tr, nl = l.size(), nr = r.size();
    if (!nr || !nl)
    {
        for (int i = 1; i <= n; i++)
            cout << (nl ? n + 1 - i : i) << ' ';
        cout << endl;
        return;
    }
    vll ans(n + 1), suml(nl), sumr(nr);
    suml[0] = l[0];
    for (int i = 1; i < nl; i++)
        suml[i] = suml[i - 1] + l[i];
    sumr[0] = r[0];
    for (int i = 1; i < nr; i++)
        sumr[i] = sumr[i - 1] + r[i];

    tl = 0, tr = 0;
    for (int i = 1, cnt; i <= n; i++)
    {
        if (a[i] == '<') ++tr;
        else
        {
            if (tl + 1 <= nr - tr)
            {
                cnt = tl + 1;
                ans[i] = (sumr[tr + cnt - 1] - (tr - 1 < 0 ? 0 : sumr[tr - 1])) * 2;
                ans[i] -= i + (tl - 1 < 0 ? 0 : suml[tl - 1]) * 2;
            }
            else
            {
                cnt = nr - tr;
                ans[i] = (sumr[tr + cnt - 1] - (tr - 1 < 0 ? 0 : sumr[tr - 1])) * 2 + n + 1;
                ans[i] -= i + (tl - 1 < 0 ? 0 : suml[tl - 1]) * 2 - (tl - cnt - 1 < 0 ? 0 : suml[tl - cnt - 1]) * 2;
            }
            ++tl;
        }
    }

    tl = nl - 1, tr = nr - 1;
    for (int i = n, cnt; i >= 1; i--)
    {
        if (a[i] == '>') --tl;
        else
        {
            if (nr - tr <= tl + 1)
            {
                cnt = nr - tr;
                ans[i] = n + 1 + i + (sumr[nr - 1] - sumr[tr]) * 2;
                ans[i] -= (tl < 0 ? 0 : suml[tl] * 2) - (tl - cnt < 0 ? 0 : suml[tl - cnt] * 2);
            }
            else
            {
                cnt = tl + 1;
                ans[i] = i + (sumr[tr + cnt] - sumr[tr]) * 2;
                ans[i] -= tl < 0 ? 0 : suml[tl] * 2;
            }
            --tr;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
