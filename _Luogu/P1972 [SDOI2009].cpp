#include "bits/stdc++.h"
using namespace std;
#define lowbit(x) (x & (-x))
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

int n, m;
int a[1000010]{}, used[1000010]{};
int ans[1000010]{};
struct ss
{
    int l, r, id;
    friend bool operator<(const ss &a, const ss &b) { return (a.r == b.r ? a.l < b.l : a.r < b.r); }
} s[1000010]{};
int t[1000010]{};

void add(int i, int k)
{
    for (; i <= n; i += lowbit(i))
        t[i] += k;
}

int ask(int l, int r)
{
    int sum = 0;
    for (; r; r -= lowbit(r))
        sum += t[r];
    --l;
    for (; l; l -= lowbit(l))
        sum -= t[l];
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> s[i].l >> s[i].r;
        s[i].id = i;
    }
    sort(s + 1, s + 1 + m);
    int l = 0, r = 1;
    while (r <= m)
    {
        while (l < s[r].r)
        {
            ++l;
            if (used[a[l]])
                add(used[a[l]], -1);
            used[a[l]] = l;
            add(l, 1);
        }
        ans[s[r].id] = ask(s[r].l, s[r].r);
        ++r;
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << '\n';
    return 0;
}