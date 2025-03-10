#include<iostream>
#include<string.h>
using namespace std;
int n,t;
string s;
int a[100005];
int f[28];

inline int v(char c){return (int)c-96;}
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        memset(f,0,sizeof(f));
        memset(a,0,sizeof(a));
        cin>>n>>s;
        for(int i=0;i<s.length();i++)
        {
            if(i!=0) a[i]=a[i-1];
            if(!f[v(s[i])])
            {
                f[v(s[i])]=1;
                a[i]++;
            }
        }
        int ans=0;
        for(int i=0;i<s.length();i++) ans+=a[i];
        cout<<ans<<endl;
    }
    return 0;
}