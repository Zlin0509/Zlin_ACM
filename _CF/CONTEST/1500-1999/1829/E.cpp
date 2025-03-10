#include<bits/stdc++.h>
using namespace std;

int n, m;
bool vis[1005][1005];
int a[1005][1005];

int dfs(int i, int j)
{
    vis[i][j] = true;
    int ans = a[i][j];
    if(i != 0 && a[i-1][j] != 0 && !vis[i-1][j])
    {
        ans+=dfs(i-1, j);
    }
    if(i != n-1 && a[i+1][j] != 0 && !vis[i+1][j])
    {
        ans+=dfs(i+1, j);
    }
    if(j != 0 && a[i][j-1] != 0 && !vis[i][j-1])
    {
        ans+=dfs(i, j-1);
    }
    if(j != m-1 && a[i][j+1] != 0 && !vis[i][j+1])
    {
        ans+=dfs(i, j+1);
    }
    return ans;
}

void solve()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            vis[i][j] = false;
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!vis[i][j] && a[i][j] != 0)
            {
                ans = max(ans, dfs(i, j));
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}