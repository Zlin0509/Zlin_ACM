#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int n, ans;
char s[22]{};

void solve()
{
    ans = 0;
    queue<int> q;
    cin >> n >> s;

    if (n <= 2)
    {
        for (int i = 0; i < n; i++)
            ans = ans * 10 + s[i] - '0';
        cout << ans << '\n';
        return;
    }

    ans = INT_MAX;

    if (n == 3)
    {
        int xa = s[0] - '0', xb = (s[1] - '0') * 10 + s[2] - '0';
        int ya = (s[0] - '0') * 10 + s[1] - '0', yb = s[2] - '0';
        ans = min(xa + xb, ya + yb);
        ans = min(ans, xa * xb);
        ans = min(ans, ya * yb);
        cout << ans << '\n';
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < i; j++)
            q.push(s[j] - '0');
        q.push((s[i] - '0') * 10 + s[i + 1] - '0');
        for (int j = i + 2; j < n; j++)
            q.push(s[j] - '0');
        int m = 0, x;
        while (!q.empty())
        {
            x = q.front();
            // cout << x << ' ';
            q.pop();
            if (x == 0)
            {
                cout << 0 << '\n';
                return;
            }
            else if (x != 1)
                m += x;
        }
        // cout << m;
        // cout << '\n';
        ans = min(ans, m);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
        solve();
}