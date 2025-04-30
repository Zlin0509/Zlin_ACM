//
// Created by Zlin on 2025/1/10.
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

struct T
{
    int t, p;
    int id;

    bool operator<(const T& b) const
    {
        return (db)p / t > (db)b.p / b.t;
    }
};

inline void Zlin()
{
    int n, v;
    cin >> n >> v;
    vector<T> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].t >> a[i].p, a[i].id = i + 1;
    sort(a.begin(), a.end());
    T p{0, 0, 0}, pp{0, 0, 0}, ppp{0, 0, 0};
    set<int> ans;
    ll cnt = 0;
    int tag = 0;
    while (v && tag != n)
    {
        if (v >= a[tag].t)
        {
            v -= a[tag].t;
            cnt += a[tag].p;
            ans.insert(a[tag].id);
            if (a[tag].t == 1)
            {
                ppp = pp;
                pp = a[tag];
            }
        }
        else if (!p.id)
            p = a[tag];
        ++tag;
    }
    if (v && pp.id && p.p > pp.p)
    {
        ans.erase(ans.find(pp.id));
        ans.insert(p.id);
        cnt += p.p - pp.p;
    }
    if (!v && pp.id && ppp.id && p.p > pp.p + ppp.p)
    {
        ans.erase(ans.find(pp.id));
        ans.erase(ans.find(ppp.id));
        ans.insert(p.id);
        cnt += p.p - pp.p - ppp.p;
    }
    cout << cnt << '\n';
    for (auto it : ans)
        cout << it << ' ';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
