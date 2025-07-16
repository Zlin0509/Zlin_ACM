#include "bits/stdc++.h"
using namespace std;

struct Node
{
    int l, r, id;

    bool operator<(const Node& n) const
    {
        if (r != n.r)
            return r < n.r;
        if (l != n.l)
            return l > n.l;
        return id < n.id;
    }
};

void solve()
{
    int n;
    cin >> n;

    set<Node> s;
    for (int i = 0; i < n; ++i)
    {
        Node x;
        cin >> x.l >> x.r;
        x.id = i;
        s.insert(x);
    }
    vector<int> res(n);
    set<int> have;
    vector<bool> check(n + 1, false);
    for (int i = 1; i <= n; i++)
        have.insert(i);
    while (!s.empty())
    {
        Node x = *s.begin();
        s.erase(s.begin());
        auto it = have.lower_bound(x.l);
        if (it == have.end() || *it > x.r)
        {
            cout << -1 << endl;
            return;
        }
        res[x.id] = *it;
        have.erase(it);
    }
    for (auto it : res)
        cout << it << ' ';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
