#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int a,n,m,x;
    cin>>a>>n>>m>>x;
    int on_x[50]{},up_x[50]{},on_a[50]{},up_a[50]{},ans=0;
    int s1=1,s2=0;
    on_a[1]=1;on_x[2]=1;up_x[2]=1;
    for(int i=3;i<n;i++)
    {
        on_a[i]=on_a[i-1]+on_a[i-2];
        on_x[i]=on_x[i-1]+on_x[i-2];
        up_a[i]=on_a[i-1];
        up_x[i]=on_x[i-1];
        s1+=on_a[i]-up_a[i];
        s2+=on_x[i]-up_x[i];
    }
    int k=(m-s1*a)/s2;
    for(int i=1;i<=x;i++)
    {
        ans+=(on_a[i]-up_a[i])*a;
        ans+=(on_x[i]-up_x[i])*k;
    }
    cout<<ans<<'\n';
}