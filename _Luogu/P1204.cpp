#include<bits/stdc++.h>
using namespace std;

struct ss
{
    int r;
    int l;
}a[5050]{};
int n;

bool cmp(const ss &a,const ss &b)
{
    return a.l<b.l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].l>>a[i].r;
    }
    sort(a+1,a+1+n,cmp);
    int ans1=0,ans2=0;
    int begin=a[1].l,end=a[1].r;
    for(int i=2;i<=n;i++)
    {
        if(a[i].l<=end)
        {
            end=a[i].r;
        }
        else
        {
            ans1=max(ans1,end-begin);
            ans2=max(ans2,a[i].l-end);
            begin=a[i].l;
            end=a[i].r;
        }
    }
    ans1=max(ans1,end-begin);
    cout<<ans1<<" "<<ans2;
}