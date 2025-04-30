#include "bits/stdc++.h"
using namespace std;
#define lowbit(x) (x & (-x))
#define ll long long
#define vi vector<int>
#define vll vector<ll>
const int N = 2e6 + 10;
int n, c, m;
int t[N], a[N], ans[N], last1[N], last2[N];
struct ss
{
    int l, r, id;
    friend bool operator<(const ss &a, const ss &b) { return (a.r == b.r ? a.l < b.l : a.r < b.r); }
} b[N];

void add(int i, int k)
{
    for (; i <= n; i += lowbit(i))
        t[i] += k;
    return;
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

void solve()
{
    cin >> n >> c >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i].l >> b[i].r, b[i].id = i;
    sort(b + 1, b + 1 + m);
    for (int i = 1, r = 0; i <= m; i++)
    {
        while (r < b[i].r)
        {
            ++r;
            if (!last2[a[r]])
                last2[a[r]] = r;
            else
            {
                if (last1[a[r]])
                    add(last1[a[r]], -1);
                last1[a[r]] = last2[a[r]];
                last2[a[r]] = r;
                add(last1[a[r]], 1);
            }
        }
        ans[b[i].id] = ask(b[i].l, b[i].r);
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}