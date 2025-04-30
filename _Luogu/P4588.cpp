#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

ll Q, M;
ll op, m;

struct ss
{
    ll sum;
    int l, r;
} T[600001]{};

void update(int now)
{
    T[now].sum = T[now * 2].sum * T[now * 2 + 1].sum % M;
}

void build(int now, int l, int r)
{
    T[now].l = l, T[now].r = r;
    if (l == r)
    {
        T[now].sum = 1;
        return;
    }
    int mid = l + r >> 1;
    build(now * 2, l, mid);
    build(now * 2 + 1, mid + 1, r);
    update(now);
}

void change(int now, int l, int r, int dir)
{
    int nl = T[now].l, nr = T[now].r;
    if (nl >= l && nr <= r)
    {
        T[now].sum = dir;
        return;
    }
    int mid = nl + nr >> 1;
    // cout << mid;
    if (mid >= l)
        change(now * 2, l, r, dir);
    if (mid < r)
        change(now * 2 + 1, l, r, dir);
    update(now);
}

void solve()
{
    cin >> Q >> M;
    build(1, 1, Q);
    for (int i = 1; i <= Q; i++)
    {
        cin >> op >> m;
        if (op == 1)
            change(1, i, i, m);
        else
            change(1, m, m, 1);
        cout << T[1].sum << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
        solve();
}