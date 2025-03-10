#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,len;
    string s;
    int a[30]{};
    cin>>n>>s;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ++a[s[i]-'a'];
    }
    sort(a,a+30,greater<int>());
    if(a[0]>n/2)
    {
        ans=a[0]*2-n;
    }
    else
    {
        ans=(n-a[0]*2)%2;
    }
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