#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    int a[200010]{},used[200010]{};
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    int now=n-1;
    while(used[now]==0&&k)
    {
        if(a[now]>n)
        {
            cout<<"No"<<endl;
            return;
        }
        ++used[now];
        now=(now-a[now]+n)%n;
        --k;
    }
    cout<<"Yes"<<endl;
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