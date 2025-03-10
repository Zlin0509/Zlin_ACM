#include<bits/stdc++.h>
using namespace std;

int n;
char a[300010]{};
int l[300010]{},r[300010]{};

int dfs(int i)
{
    if(i==0) return 1<<30;
    if(l[i]==0&&r[i]==0) return 0;
    return min(dfs(l[i])+(a[i]!='L'),dfs(r[i])+(a[i]!='R'));
}

void solve()
{
    memset(l,sizeof(l),0);memset(r,sizeof(r),0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>l[i]>>r[i];

    int ans=dfs(1);
    cout<<ans<<endl;
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