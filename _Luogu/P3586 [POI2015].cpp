#include "bits/stdc++.h"
using namespace std;
#define lowbit(x) (x & (-x))
#define ll long long
#define vi vector<int>
#define vll vector<ll>
const int N = 1e6 + 10;
ll n, m, len, p1, p2;
ll t1[N]{}, t2[N]{}, tt[N]{}, arr[N]{};
ll tr1[N]{}, tr2[N]{}, ans;
char z[N]{};

void add(ll *tr, int i, int k)
{
    for (; i <= len; i += lowbit(i))
        tr[i] += k;
}

ll ask(ll *tr, int l, int r)
{
    ll sum = 0;
    for (; r; r -= lowbit(r))
        sum += tr[r];
    --l;
    for (; l; l -= lowbit(l))
        sum -= tr[l];
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> z[i] >> t1[i] >> t2[i], tt[i] = t2[i];
    tt[m + 1] = 0;
    sort(tt + 1, tt + 2 + m);
    len = unique(tt + 1, tt + 2 + m) - tt - 1;
    add(tr2, lower_bound(tt + 1, tt + len + 1, 0) - tt, n);
    add(tr2, lower_bound(tt + 1, tt + len + 1, 0) - tt + 1, -n);
    for (int i = 1; i <= m; i++)
    {
        if (z[i] == 'U')
        {
            p1 = lower_bound(tt + 1, tt + len + 1, t2[i]) - tt;
            p2 = lower_bound(tt + 1, tt + len + 1, arr[t1[i]]) - tt;
            arr[t1[i]] = t2[i];
            add(tr1, p2, -tt[p2]);
            add(tr1, p1, tt[p1]);
            add(tr2, p2, -1);
            add(tr2, p1, 1);
        }
        else
        {
            p1 = lower_bound(tt + 1, tt + len + 1, t2[i]) - tt;
            ans = ask(tr2, p1 + 1, len) * t2[i] + ask(tr1, 1, p1);
            cout << (ans >= t2[i] * t1[i] ? "TAK" : "NIE") << '\n';
        }
    }
    return 0;
}