//
// Created by Zlin on 2025/2/11.
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

class Ftree
{
private:
    vi t;

public:
    Ftree(int n) : t(n + 1, 0)
    {
    }

    void upd(int i, int v)
    {
        while (i < t.size())
        {
            t[i] += v;
            i += i & -i;
        }
    }

    int qry1(int i)
    {
        int s = 0;
        while (i > 0)
        {
            s += t[i];
            i -= i & -i;
        }
        return s;
    }

    int qry2(int l, int r)
    {
        return qry1(r) - qry1(l - 1);
    }
};

struct Node
{
    int val, id;

    bool operator<(const Node& x) const
    {
        return val < x.val;
    }
};

struct Query
{
    int qid, l, r;
};

inline void Zlin()
{
    int n, m;
    cin >> n >> m;
    vector<Node> a(n + 1);
    vi t(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].val, a[i].id = i, t[i] = a[i].val;
    sort(a.begin() + 1, a.end());;
    vi ans(m);
    vector<vector<Query>> q(n + 1);
    for (int i = 0; i < m; i++)
    {
        int l, r, c;
        cin >> l >> r >> c;
        q[t[c]].push_back({i, l, r});
    }
    Ftree ft(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (auto it : q[i])
        {
            int l = it.l;
            int r = it.r;
            int id = it.qid;
            ans[id] = ft.qry2(l, r) + l;
        }
        ft.upd(a[i].id, 1);
    }
    for (int i = 0; i < m; i++)
        cout << ans[i] << endl;
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
