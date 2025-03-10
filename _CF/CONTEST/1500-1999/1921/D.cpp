#include <bits/stdc++.h>
#define ll long long
#define ex exit(0)
#define _endl_ puts("");
#define inl inline
#define null NULL
#define pll pair<ll,ll>
#define mkp make_pair
using namespace std;
ll a[200005], b[200005];
ll f[200005], g[200005];

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int j = 1; j <= m; j++)
        {
            cin >> b[j];
        }
        sort(a + 1, a + n + 1);
        sort(b + 1, b + m + 1);
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++)
        {
            f[i] = f[i - 1] + abs(a[i] - b[m - i + 1]);
        }
        memset(g, 0, sizeof(g));
        for (int i = n; i >= 1; i--)
        {
            g[i] = g[i + 1] + abs(a[i] - b[n - i + 1]);
        }
        ll ans = 0;
        for (int i = 0; i <= n; i++)
        {
            ans = max(ans, f[i] + g[i + 1]);
        }
        cout << ans << endl;
    }
    return 0;
}
