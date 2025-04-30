#include<bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int s,t,w;
    string jam;
    cin>>s>>t>>w;
    cin>>jam;
    for(int q=0;q<5;q++)
    {
        for(int i=w-1;i>=0;i--)
        {
            if(jam[i]-'a'+1+w-i<=t)
            {
                ++jam[i];
                for(int j=i+1;j<w;j++) jam[j]=jam[j-1]+1;
                cout<<jam<<'\n';
                break;
            }
        }
    }
}