#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

void solve()
{
    int n;
    cin >> n;
    vi a(n + 1), b(n + 2), c(n + 2), num(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // b[0] = 0;
    // c[n + 1] = 0;
    // for (int i = 0; i <= n; i++)
    //     num[i] = 0;
    int l = 0;
    for (int i = 1; i <= n; i++)
    {
        ++num[a[i]];
        while(num[l])
        {
            ++l;
        }
        b[i] = l;
    }
    for (int i = 0; i <= n; i++)
        num[i] = 0;
    l = 0;
    for (int i = n; i >= 1; i--)
    {
        ++num[a[i]];
        while(num[l])
        {
            ++l;
        }
        c[i] = l;
    }
    for (int i = 1; i < n; i++)
    {
        // cout << b[i] << c[i + 1] << '\n';
        if (b[i] == c[i + 1])
        {
            cout << 2 << '\n';
            cout << 1 << " " << i << '\n';
            cout << i + 1 << " " << n << '\n';
            return;
        }
    }
    cout << "-1" << '\n';
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