//
// Created by 27682 on 2025/3/19.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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

    void upd(int i, ll val)
    {
        while (i < t.size())
        {
            t[i] += val;
            i += i & -i;
        }
    }

    ll qry1(int i)
    {
        ll res = 0;
        while (i)
        {
            res += t[i];
            i -= i & -i;
        }
        return res;
    }

    ll qry2(int l, int r)
    {
        return qry1(r) - qry1(l - 1);
    }
} t, t1;

struct node
{
    int id, val;

    bool operator<(const node& b) const
    {
        return val < b.val;
    }
};

inline void Zlin()
{
    int n;
    cin >> n;
    vi a(n + 1), ans(n + 1);
    vector<node> lx, rx, mid;
    vi sum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == i)
            mid.emplace_back(i, a[i]);
        else if (a[i] > i)
            rx.emplace_back(i, a[i]);
        else if (a[i] < i)
            lx.emplace_back(i, a[i]), sum[i] = 1;
    }
    sort(lx.begin(), lx.end());
    sort(rx.begin(), rx.end());
    t.init(n + 1);

    for (auto [id, val] : mid)
        ans[val] = 0, t.upd(id, 1);
    for (auto [id, val] : rx)
    {
        ans[val] = val - id - t.qry2(id + 1, val);
        t.upd(id, 1);
    }
    for (auto [id, val] : rx)
        t.upd(id, -1);
    for (auto [id, val] : mid)
        t.upd(id, -1);

    for (int i = 2; i <= n; i++)
        sum[i] += sum[i - 1];
    for (auto [id, val] : lx)
    {
        ans[val] = sum[n] - sum[id - 1] + t.qry2(1, id);
        t.upd(id, 1);
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
