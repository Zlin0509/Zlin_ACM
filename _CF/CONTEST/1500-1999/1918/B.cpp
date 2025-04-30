#include<bits/stdc++.h>
using namespace std;

struct ss
{
    int a;
    int b;
}a[200010]{};

bool cmp(const ss &a,const ss &b)
{
    return a.a<b.a;
}

void solve()
{
    memset(a,sizeof(a),0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i].a;
    for(int i=0;i<n;i++) cin>>a[i].b;
    sort(a,a+n,cmp);
    for(int i=0;i<n-1;i++) cout<<a[i].a<<" ";
    cout<<a[n-1].a<<endl;
    for(int i=0;i<n-1;i++) cout<<a[i].b<<" ";
    cout<<a[n-1].b<<endl;
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