#include<bits/stdc++.h>
using namespace std;

int m,n,k,l,d;

struct ss
{
    int place;
    int num=0;
}x[1010]{},y[1010]{};

bool cmp(const ss &a,const ss &b)
{
    if(a.num!=b.num)
        return a.num>b.num;
    return a.place<b.place;
}

bool cmp1(const ss &a,const ss &b)
{
    return a.place<b.place;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>m>>n>>k>>l>>d;
    int x1,y1,x2,y2;
    for(int i=1;i<=max(n,m);i++)
    {
        y[i].place=i;x[i].place=i;
    }
    for(int i=0;i<d;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        if(x1==x2) ++y[min(y1,y2)].num;
        if(y1==y2) ++x[min(x1,x2)].num;
    }
    sort(x+1,x+m+1,cmp);sort(y+1,y+1+n,cmp);
    sort(x+1,x+1+k,cmp1);sort(y+1,y+1+l,cmp1);
    for(int i=1;i<k;i++)
    {
        cout<<x[i].place<<" ";
    }
    cout<<x[k].place<<'\n';
    for(int i=1;i<l;i++)
    {
        cout<<y[i].place<<' ';
    }
    cout<<y[l].place;
}