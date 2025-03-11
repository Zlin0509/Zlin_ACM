//
// Created by 27682 on 2025/3/11.
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

struct Ftree
{
private:
    vll t;

public:
    void init(int n)
    {
        t.assign(n + 1, 0);
    }

    void upd(ll i, ll v)
    {
        while (i < t.size())
        {
            t[i] += v;
            i += i & -i;
        }
    }

    ll qry1(ll i)
    {
        ll s = 0;
        while (i > 0)
        {
            s += t[i];
            i -= i & -i;
        }
        return s;
    }

    ll qry2(ll l, ll r)
    {
        if (r < l)
            return 0;
        return qry1(r) - qry1(l - 1);
    }
} t;

struct node
{
    int x, val;

    bool operator<(const node& b) const
    {
        return x < b.x;
    }
};

inline void Zlin()
{
    int n, m, q;
    cin >> n >> m >> q;
    t.init(n);
    vll V(n + 1);
    set<ll> have;
    vector<node> ss(m);
    for (int i = 0; i < m; i++)
        cin >> ss[i].x;
    for (int i = 0; i < m; i++)
        cin >> ss[i].val;
    sort(ss.begin(), ss.end());
    for (auto [x,val] : ss)
    {
        have.insert(x);
        V[x] = val;
    }
    for (int i = 0; i < m - 1; i++)
    {
        ll len = ss[i + 1].x - ss[i].x - 1;
        ll val = V[ss[i].x] * len * (len + 1) / 2;
        t.upd(ss[i].x, val);
    }
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            ll x, v;
            cin >> x >> v;
            V[x] = v;
            ll l = *prev(have.upper_bound(x));
            ll r = *have.upper_bound(x);
            // 更新l位置
            ll len = r - l - 1;
            ll val = V[l] * len * (len + 1) / 2;
            t.upd(l, -val);
            len = x - l - 1;
            val = V[l] * len * (len + 1) / 2;
            t.upd(l, val);
            // 更新x位置
            len = r - x - 1;
            val = V[x] * len * (len + 1) / 2;
            t.upd(x, val);
            have.insert(x);
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            ll lx = *have.lower_bound(l);
            ll rx = *prev(have.upper_bound(r));
            ll res = t.qry2(lx, rx - 1);
            if (have.find(l) == have.end())
            {
                int len = lx - l;
                int llx = *prev(have.find(lx));
                res += V[llx] * len * (len + 1) / 2;
            }
            if (have.find(r) == have.end())
            {
                int len = r - rx;
                int rrx = *next(have.find(rx));
                int k = rrx - r;
                res += V[rx] * len * (k + k + len - 1) / 2;
            }
            cout << res << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
