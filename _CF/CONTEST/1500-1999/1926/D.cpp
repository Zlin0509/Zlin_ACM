#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

void solve()
{
    int n, ans = 0;
    cin >> n;
    map<int, int> a;
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        if (!a[x])
            ++ans, ++a[((1 << 31) - 1) ^ x];
        else
            --a[x];
    }
    cout << ans << '\n';
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