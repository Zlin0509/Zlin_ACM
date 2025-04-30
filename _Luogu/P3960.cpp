#include "bits/stdc++.h"
using namespace std;
#define lowbit(x) (x & (-x))
#define ll long long
#define vi vector<int>
#define vll vector<ll>
const int N = 3e5 + 10;

ll n, m, q;
ll x[N], y[N], I[N];
ll t[N * 3], change[N], ans[N], len[N], len2[N], h[N], arr[N * 3];
bool cmp(ll p1, ll p2) { return x[p1] == x[p2] ? p1 < p2 : x[p1] < x[p2]; }
void add(ll *tree, ll size, ll i, ll k)
{
    for (; i <= size; i += lowbit(i))
        tree[i] += k;
}

ll query(ll *tree, ll l, ll r)
{
    ll sum = 0;
    for (; r; r -= lowbit(r))
        sum += tree[r];
    --l;
    for (; l; l -= lowbit(l))
        sum -= lowbit(l);
    return sum;
}

ll search(ll *arr, ll size, ll num)
{
    int l = 1, r = size, mid;
    while (l < r)
    {
        mid = l + r >> 1;
        if (query(arr, 1, mid) < num)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

void Zlin()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= q; i++)
        cin >> x[i] >> y[i], I[i] = i;
    sort(I + 1, I + 1 + q, cmp);
    for (int i = 1; i < m; i++)
        add(t, m - 1, i, 1);
    for (int i = 1; i <= n; i++)
        len[i] = m - 1;
    for (int i = 1, top = 0, pos; i <= q; i++)
    {
        if (x[I[i - 1]] != x[I[i]])
            while (top)
                add(t, m - 1, change[top--], 1);
        if (y[I[i]] > len[x[I[i]]])
            continue;
        pos = search(t, m - 1, y[I[i]]);
        add(t, m - 1, pos, -1);
        change[++top] = pos;
        --len[x[I[i]]];
        ans[I[i]] = (x[I[i]] - 1) * m + pos;
    }
    memset(t, 0, sizeof(t));
    len[n + 1] = n, h[n + 1] = q;
    for (int i = 1, iter = 0; i <= n; i++)
    {
        while (iter <= q && x[I[iter]] < i)
            ++iter;
        h[i] = iter - 1;
    }
    for (int i = 1; i <= n; i++)
        arr[q + i] = i * m, len2[i] = m - 1, len[i] = 0, add(t + h[n + 1], n + q, i, 1);
    for (int i = 1, pos; i <= q; i++)
    {
        pos = search(t + h[n + 1], n + q, x[i]);
        add(t + h[n + 1], n + q, pos, -1);
        add(t + h[n + 1], n + q, ++len[n + 1], 1);
        if (ans[i])
        {
            arr[len[n + 1] + h[n + 1]] = ans[i];
            add(t + h[x[i]], h[x[i] + 1] - h[x[i]], ++len[x[i]], 1);
            arr[len[x[i]] + h[x[i]]] = arr[h[n + 1] + pos];
            --len2[x[i]];
        }
        else
        {
            if (y[i] != m)
            {
                int pos2 = search(t + h[x[i]], h[x[i] + 1] - h[x[i]], y[i] - len2[x[i]]);
                add(t + h[x[i]], h[x[i] + 1] - h[x[i]], pos2, -1);
                ans[i] = arr[h[x[i]] + pos2];
                add(t + h[x[i]], h[x[i] + 1] - h[x[i]], ++len[x[i]], 1);
                arr[h[x[i]] + len[x[i]]] = arr[h[n + 1] + pos];
            }
            else
                ans[i] = arr[h[n + 1] + pos];
            arr[h[n + 1] + len[n + 1]] = ans[i];
        }
    }

    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Zlin();
    return 0;
}