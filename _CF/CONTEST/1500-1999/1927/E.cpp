#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[200010]{};
int l=1,i=1;

void go_right()
{
    while(i<=n)
    {
        a[i]=l;
        ++l;
        i+=k;
    }
    ++i;
    while(i>n)
    {
        i-=k;
    }
}

void go_left()
{
    while(i>=1)
    {
        a[i]=l;
        ++l;
        i-=k;
    }
    ++i;
    while(i<1)
    {
        i+=k;
    }
}

void solve()
{
    memset(a,sizeof(a),0);
    l=1,i=1;
    cin>>n>>k;

    while(l<n)
    {
        go_right();
        go_left();
    }

    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
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