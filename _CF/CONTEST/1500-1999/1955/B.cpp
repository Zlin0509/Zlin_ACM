#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, c, d;
    cin >> n >> c >> d;
    vector<int> a(n * n);
    for (int i = 0; i < n * n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> b(n * n);
    b[0] = a[0];
    // cout << b[0] << '\n';
    for (int j = 1; j < n; j++)
    {
        b[j * n] = b[(j - 1) * n] + c;
    }
    for (int i = 1; i < n; i++)
    {
        b[i] = b[i - 1] + d;
        for (int j = 1; j < n; j++)
        {
            b[i + j * n] = b[i + (j - 1) * n] + c;
        }
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < n * n; i++)
    {
        if (a[i] != b[i])
        {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
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