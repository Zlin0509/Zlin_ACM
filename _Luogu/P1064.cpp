#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0;
int l, r;
int dp[40010]{}, v[65]{}, p[65]{}, q[65]{};
vector<vector<int>> qq(65);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> v[i] >> p[i] >> q[i];
        if (q[i])
            qq[q[i]].push_back(i);
    }
    for (int i = 1; i <= m; i++)
    {
        if (!q[i])
        {
            l = 0, r = 0;
            if (qq[i].size() == 1)
                l = qq[i][0];
            if (qq[i].size() == 2)
                l = qq[i][0], r = qq[i][1];
            for (int j = n; j >= v[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - v[i]] + v[i] * p[i]);
                if (l && j >= v[l] + v[i])
                    dp[j] = max(dp[j], dp[j - v[i] - v[l]] + v[i] * p[i] + v[l] * p[l]);
                if (r && j >= v[r] + v[i])
                    dp[j] = max(dp[j], dp[j - v[i] - v[r]] + v[i] * p[i] + v[r] * p[r]);
                if (l && r && j >= v[i] + v[l] + v[r])
                    dp[j] = max(dp[j], dp[j - v[i] - v[l] - v[r]] + v[i] * p[i] + v[l] * p[l] + v[r] * p[r]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    cout << ans;
}