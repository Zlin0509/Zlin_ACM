#include <bits/stdc++.h>
using namespace std;

char cc;
int te1, te2, ts1, ts2;
int n;
int t[10010]{}, p[10010]{}, c[10010]{}, dp[10010]{};
int tz;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> te1 >> cc >> te2 >> ts1 >> cc >> ts2;
    tz = 60 * (ts1 - te1) + ts2 - te2;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> t[i] >> c[i] >> p[i];
    for (int i = 1; i <= n; i++)
    {
        if (!p[i])
        {
            for (int j = t[i]; j <= tz; j++)
                dp[j] = max(dp[j], dp[j - t[i]] + c[i]);
        }
        else
        {
            for (int l = 1; l <= p[i]; l++)
                for (int j = tz; j >= l * t[i]; j--)
                    dp[j] = max(dp[j], dp[j - t[i]] + c[i]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= tz; i++)
        ans = max(ans, dp[i]);
    cout << ans;
}