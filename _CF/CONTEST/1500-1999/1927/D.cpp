#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,q;
    int a[200010]{};
    vector<int>b;
    cin>>n;
    b.push_back(1);
    cin>>a[1];
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=a[i-1])
            b.push_back(i);
    }
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        auto it=upper_bound(b.begin(),b.end(),l);
        if(*it>r)
        {
            cout<<"-1 -1"<<endl;
        }
        else if(it==b.end())
        {
            cout<<"-1 -1"<<endl;
        }
        else
        {
            cout<<l<<" "<<*it<<endl;
        }
    }
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