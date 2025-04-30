#include "bits/stdc++.h"
using namespace std;
#define lowbit(x) (x & (-x))
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

int n, len;
int ans[100010]{}, t[100010]{};
int a[100010]{}, c[100010]{};
int tot = 0, head[100010]{};
struct Edge
{
    int to, next;
} e[100010]{};

void add_e(int u, int v)
{
    ++tot;
    e[tot].to = v;
    e[tot].next = head[u];
    head[u] = tot;
}

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

void dfs(int u)
{
    ans[u] = -ask(a[u] + 1, len);
    for (int i = head[u]; i; i = e[i].next)
        dfs(e[i].to);
    ans[u] += ask(a[u] + 1, len);
    add(a[u], 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], c[i] = a[i];
    sort(c + 1, c + 1 + n);
    len = unique(c + 1, c + 1 + n) - c - 1;
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(c + 1, c + 1 + len, a[i]) - c;
    for (int i = 2, j; i <= n; i++)
    {
        cin >> j;
        add_e(j, i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
}