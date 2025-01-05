#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

vi cnt(200010);
vl ans(200010);

void dd()
{
    // cout << 10 / 10 * 10 << '\n';
    for (int i = 1; i < 200010; i++)
        cnt[i] = cnt[i / 10] + i % 10;
    for (int i = 1; i < 200010; i++)
        ans[i] = ans[i - 1] + cnt[i];
}

void solve()
{
    int x;
    cin >> x;
    cout << ans[x] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    dd();
    while (T--)
    {
        solve();
    }
}