#include<bits/stdc++.h>
using namespace std;

bool cmp(const int a,const int b)
{
    return a>b;
}

void solve()
{
    int n,m,len=0,num=0;
    int a[200010]{};
    cin>>n>>m;
    for(int i=1,q;i<=n;i++)
    {
        cin>>q;
        int x=q,y=0;
        while(x>0)
        {
            ++len;
            x/=10;
        }//计算总共有几位数;
        x=q;
        while(x%10==0)
        {
            x/=10;
            ++y;
        }//计算a[i]有几个零;
        if(y!=0)
        {
            a[num++]=y;
        }
    }
    sort(a,a+num,cmp);
    for(int i=0;i<num;i++)
    {
        if(i%2==0)
        {
            len-=a[i];
        }
    }
    len>m?cout<<"Sasha"<<endl:cout<<"Anna"<<endl;
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

