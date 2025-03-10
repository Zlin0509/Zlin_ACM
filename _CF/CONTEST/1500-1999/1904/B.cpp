#include<bits/stdc++.h>
using namespace std;

struct ss
{
    int num;
    int place;
}a[100010]{};

bool cmp(const ss &a,const ss &b)
{
    return a.num<b.num;
}

void solve()
{
    int n;
    int ans[100010]{};
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].num;
        a[i].place=i;
    }
    sort(a,a+n,cmp);

    long long sum=0,num=0;
    for(int i=0;i<n;i++)
    {
        if(num<=i) sum+=a[i].num;
        int x=a[i].num;
        a[i].num=0;
        while(a[num].num<=sum&&num<n)
        {
            sum+=a[num].num;
            ++num;
        }
        a[i].num=x;
        ans[a[i].place]=num-1;
    }

    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
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