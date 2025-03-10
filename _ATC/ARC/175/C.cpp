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

constexpr int inf = 0x3f3f3f3f;

inline void Zlin()
{
    int n;
    cin >> n;
    vector<pii> a(n);
    for (pii& it : a)
        cin >> it.first >> it.second;
    vi ans(n);
    int lx = 0, rx, cnt;
    set<pii> l, r;
    auto upd = [&](int id)
    {
        if (l.find({a[id].first, id}) != l.end())
            l.erase(l.find({a[id].first, id}));
        if (r.find({a[id].second, id}) != r.end())
            r.erase(r.find({a[id].second, id}));
    };
    for (int i = 0; i < n; i++)
    {
        auto [x,y] = a[i];

        if (!r.empty() && x > r.begin()->first)
        {
            rx = 0;
            cnt = inf;
            while (!r.empty() && r.begin()->first < x)
            {
                auto [val,id] = *r.begin();
                rx = max(rx, id);
                cnt = min(cnt, val);
                upd(id);
            }
            if (lx == 0)
            {
                for (int j = lx; j <= rx; j++)
                {
                    ans[j] = cnt;
                    upd(j);
                }
            }
            else if (ans[lx - 1] < cnt)
            {
                for (int j = lx; j <= rx; j++)
                {
                    ans[j] = max(ans[j - 1], a[j].first);
                    upd(j);
                }
            }
            else
            {
                for (int j = lx; j <= rx; j++)
                {
                    ans[j] = cnt;
                    upd(j);
                }
            }
            lx = rx + 1;
        }
        if (!l.empty() && y < prev(l.end())->first)
        {
            rx = 0;
            cnt = 0;
            while (!l.empty() && prev(l.end())->first > y)
            {
                auto [val,id] = *prev(l.end());
                rx = max(rx, id);
                cnt = max(cnt, val);
                upd(id);
            }
            if (lx == 0)
            {
                for (int j = lx; j <= rx; j++)
                {
                    ans[j] = cnt;
                    upd(j);
                }
            }
            else if (ans[lx - 1] < cnt)
            {
                for (int j = lx; j <= rx; j++)
                {
                    ans[j] = max(ans[j - 1], a[j].first);
                    upd(j);
                }
            }
            else
            {
                for (int j = lx; j <= rx; j++)
                {
                    ans[j] = cnt;
                    upd(j);
                }
            }
            lx = rx + 1;
        }

        l.insert({x, i}), r.insert({y, i});
    }

    if (lx != n)
    {
        int lt = prev(l.end())->first, rt = r.begin()->first;
        if (lx == 0)
        {
            for (int i = lx; i < n; i++)
            {
                ans[i] = lt;
                upd(i);
            }
        }
        else if (ans[lx - 1] > rt)
        {
            for (int i = lx; i < n; i++)
            {
                ans[i] = rt;
                upd(i);
            }
        }
        else
        {
            for (int i = lx; i < n; i++)
            {
                ans[i] = max(ans[i - 1], a[i].first);
                upd(i);
            }
        }
    }
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