#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n;
ll a[200010]{}, b[200010]{};
ll ans, m;

void solve()
{
    bool check = false;
    ans = 1;
    m = INT_MAX;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i <= n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
    {
        ans += abs(a[i] - b[i]);
        if ((a[i] <= b[n] && b[i] >= b[n]) || (b[i] <= b[n] && a[i] >= b[n]))
            check = true;
        m = min(m, abs(a[i] - b[n]));
        m = min(m, abs(b[i] - b[n]));
    }
    if (check)
    {
        cout << ans << '\n';
        return;
    }
    cout << ans + m << '\n';
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