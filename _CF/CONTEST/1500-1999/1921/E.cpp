#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int h,w,x1,y1,x2,y2,x;
    cin>>h>>w>>x1>>y1>>x2>>y2;
    if((x2-x1)%2==0)
    {
        if(x1>=x2)
        {
            cout<<"Draw"<<endl;
            return;
        }
        if(y1==y2)
        {
            cout<<"Bob"<<endl;
            return;
        }
        if(y1<y2) x=y2-1;
        else x=w-y2;
        if(x2-2*x>=x1) cout<<"Bob"<<endl;
        else cout<<"Draw"<<endl;
    }
    else
    {
        ++x1;
        if(y1<y2) ++y1;
        if(y1>y2) --y1;
        if(x1>x2)
        {
            cout<<"Draw"<<endl;
            return;
        }
        if(y1==y2)
        {
            cout<<"Alice"<<endl;
            return;
        }
        if(y1<y2) x=w-y1;
        else x=y1-1;
        if(x2-2*x>=x1) cout<<"Alice"<<endl;
        else cout<<"Draw"<<endl;
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