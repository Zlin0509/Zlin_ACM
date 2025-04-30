#include<bits/stdc++.h>
using namespace std;

int n;
long long sum=0;

void solve()
{
    sum=0;
    cin>>n;
    for(int i=0,x;i<n;i++)
    {
        cin>>x;
        sum+=x;
    }
    long long x=sqrt(sum);
    sum==x*x?cout<<"YES":cout<<"NO";
    cout<<endl;
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