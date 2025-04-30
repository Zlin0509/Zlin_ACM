#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;
using vl = vector<long long>;
using vi = vector<int>;

ll h, n;
ll a[200010]{}, c[200010]{};

ll sum(ll t)
{
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans = ans + a[i] + a[i] * ((t - 1) / c[i]);
    return ans;
}

void solve()
{
    cin >> h >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    ll l = 1, r = 1e16, mid;
    while (l < r)
    {
        mid = l + r >> 1;
        // cout << l << " " << r << " " << mid << '\n';
        if (sum(mid) < h)
            l = mid + 1;
        else
            r = mid;
        // cout << '\n';
        // cout << sum(mid) << " " << h << '\n';
    }
    cout << l << '\n';
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