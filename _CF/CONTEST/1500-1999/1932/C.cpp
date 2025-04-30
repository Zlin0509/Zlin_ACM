#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

void solve()
{
    int n, m;
    cin >> n >> m;
    vi a(n);
    vl ans(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    string x;
    cin >> x;
    int l = 0, r = n - 1;
    for (int i = 0; i < n - 1; i++)
        x[i] == 'L' ? ++l : --r;
    ans[n - 1] = a[l] % m;
    for (int i = n - 2; i >= 0; i--)
    {
        if (x[i] == 'L')
        {
            --l;
            ans[i] = ans[i + 1] * a[l] % m;
        }
        else
        {
            ++r;
            ans[i] = ans[i + 1] * a[r] % m;
        }
        // cout << ans[i] << '\n';
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}