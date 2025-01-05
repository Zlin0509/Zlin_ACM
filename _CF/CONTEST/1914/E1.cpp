#include<bits/stdc++.h>
using namespace std;

struct ball{
    int a;
    int b;
    long long sum;
}a[200010]{};

int n;
long long ans=0;

bool cmp(const ball &a,const ball &b)
{
    return a.sum>b.sum;
}

void solve()
{
    ans=0;
    memset(a,sizeof(a),0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i].a;
    for(int i=0;i<n;i++) cin>>a[i].b,a[i].sum=a[i].a+a[i].b;
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++)
    {
        if(i%2==0) ans+=a[i].a-1;
        else ans-=a[i].b-1;
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