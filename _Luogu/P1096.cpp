#include<bits/stdc++.h>
using namespace std;

int n;
long long a[210]{};
char ans[1000001]{};
int len=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>n;
    ans[0]='2';
    len=0;
    for(int i=2;i<=n;i++)
    {
        int x=(ans[0]-'0')*2+2;
        int check=x/10;
        x%=10;
        ans[0]=x+'0';
        for(int j=1;j<=len;j++)
        {
            x=(ans[j]-'0')*2+check;
            check=x/10;
            x%=10;
            ans[j]=x+'0';
        }
        if(check!=0)
        {
            ans[++len]=check+'0';
        }
    }
    for(int i=len;i>=0;i--)
    {
        cout<<ans[i];
    }
}   