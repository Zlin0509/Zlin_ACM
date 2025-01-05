#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

int n;

void output()
{
    for (int i = n; i >= 1;i--)
    {
        cout << "1 " << i << " ";
        for (int j = 1; j <= n;j++)
            cout << j << " ";
        cout << '\n';
        cout << "2 " << i << " ";
        for (int j = 1; j <= n; j++)
            cout << j << " ";
        cout << '\n';
    }
}

void solve()
{
    cin >> n;
    ll ans = 0, num = n * 2;
    for (int i = 1; i <= n; i++)
        ans += i * i * 2 - i;
    cout << ans << " " << num << '\n';
    output();
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