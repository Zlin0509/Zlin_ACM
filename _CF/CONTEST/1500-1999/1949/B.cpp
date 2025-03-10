#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

int a[100010]{}, b[100010]{};
int n, ans;

void check(int t)
{
    int res = 1e9;
    for (int i = 1; i <= t; i++)
    {
        res = min(res, abs(a[i] - b[i + n - t]));
    }
    for (int i = t + 1; i <= n; i++)
    {
        res = min(res, abs(a[i] - b[i - t]));
    }
    ans = max(ans, res);
}

void solve()
{
    ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);

    for (int t = 1; t <= n; t++)
    {
        check(t);
    }
    cout << ans << endl;
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