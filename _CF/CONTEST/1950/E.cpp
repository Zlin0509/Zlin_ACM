#include<bits/stdc++.h>
using namespace std;

char s[200010]{},c;
int n,check=0;
int used[30]{};

void solve()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>s[i];
    for(int i=1;i<n;i++)
    {
        if(n%i!=0) continue;
        check=0;
        for(int j=0;j<i;j++)
        {
            memset(used,0,sizeof(used));
            c=s[j];
            ++used[s[j]-'a'];
            int z=0,num=1;
            for(int q=j+i;q<n;q+=i)
            {
                if(c!=s[q])
                {
                    if(used[s[q]-'a']==0) ++num;
                    ++used[s[q]-'a'];
                    ++z;
                }
            }
            if(z==n/i-1&&num==2) check+=1;
            else check+=z;
            if(check>1) break;
        }
        if(check==1||check==0)
        {
            cout<<i<<'\n';
            return;
        }
    }
    cout<<n<<'\n';
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