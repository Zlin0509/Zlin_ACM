#include <bits/stdc++.h>
using namespace std;

int n, c;
int w[1010]{}, used[1010]{};
long long sum[1010]{};
long long ans = INT_MIN;

void dfs(int i,long long all)
{
    if(all>c)
        return;
    if(sum[i-1]+all<=c)
    {
        ans = max(ans, sum[i - 1] + all);
        return;
    }
    ans = max(ans, all);
    for (int j = 1; j < i;j++)
        dfs(j, all + w[j]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c;
    for (int i = 1; i <= n;i++)
    {
        cin >> w[i];
        sum[i] = sum[i - 1] + w[i];
    }
    dfs(n + 1, 0);
    cout << ans << '\n';
}