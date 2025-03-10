#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    int a[200010]{};
    long long sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%n!=0)
    {
        cout<<"NO"<<endl;
        return;
    }
    sum/=n;
    for(int i=0;i<n;i++)
    {
        if(a[i]>=sum)
        {
            a[i]-=sum;
            a[i+1]+=a[i];
        }
        else
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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