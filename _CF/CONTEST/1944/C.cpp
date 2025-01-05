#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

int n, k;
int cnt[50010]{};

void solve()
{
    memset(cnt, 0, sizeof(cnt));
    cin >> n >> k;
    vi a, b;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        ++cnt[x];
    }
    for (int i = 1, x; i <= n; i++)
        cin >> x;
    int n1 = 0, n2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == 0 && n2 + 2 <= k * 2)
            b.push_back(i), b.push_back(i), n2 += 2;
        if (cnt[i] == 2 && n1 + 2 <= k * 2)
            a.push_back(i), a.push_back(i), n1 += 2;
    }
    for (int i = 1; i <= n; i++)
    {
        if (n1 < k * 2 && n2 < k * 2 && cnt[i] == 1)
            a.push_back(i), b.push_back(i), ++n1, ++n2;
    }
    for (auto it : a)
        cout << it << ' ';
    cout << '\n';
    for (auto it : b)
        cout << it << ' ';
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
        solve();
}