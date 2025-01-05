#include<bits/stdc++.h>
using namespace std;

int n,m;
set<int>s;

void check(int p)
{
    if(p%2==0&&(p+2)/2>=m) s.insert(p);
}

void solve()
{
    s.clear();
    cin>>n>>m;
    int a=n-m;
    for(int i=1;i<=sqrt(a);i++)
    {
        if(a%i==0) check(i),check(a/i);
    }
    a=n+m-2;
    for(int i=1;i<=sqrt(a);i++)
    {
        if(a%i==0) check(i),check(a/i);
    }
    cout<<s.size()<<endl;
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