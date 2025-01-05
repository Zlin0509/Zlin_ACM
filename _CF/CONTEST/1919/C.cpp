#include<bits/stdc++.h>
using namespace std;

struct ss{
    int b;
    int c;
    int ans;
}f[200010];

int n;
int a[200010]{};

void solve()
{
    memset(f,sizeof(f),0);memset(a,sizeof(a),0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    f[1].b=1;f[1].c=0;f[1].ans=0;
    for(int i=2;i<=n;i++)
    {
        f[i]=f[i-1];
        int x=a[i]-a[f[i-1].b],y=a[i]-a[f[i-1].c];
        if(x>0&&y>0)
        {
            if(f[i-1].c==0)
            {
                f[i].c=i;
            }
            else{
                x>y?f[i].b=i:f[i].c=i;
                ++f[i].ans;
            };
        }
        else if(x<=0&&y<=0)
        {
            abs(x)>abs(y)?f[i].c=i:f[i].b=i;
        }
        else
        {
            x<=0?f[i].b=i:f[i].c=i;
        }
    }
    cout<<f[n].ans<<endl;
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