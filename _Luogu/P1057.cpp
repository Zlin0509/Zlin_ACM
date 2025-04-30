#include<bits/stdc++.h>
using namespace std;

int n,m;
int round1[1010]{},round2[1010]{};

void round_copy()
{
    for(int i=0;i<n;i++)
    {
        round2[i]=round1[i];
        round1[i]=0;
    }
}

void round_remove()
{
    for(int i=0;i<n;i++)
    {
        round1[i]=round2[(i+1)%n]+round2[(i-1+n)%n];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    round2[0]=1;
    for(int i=0;i<m;i++)
    {
        round_remove();
        round_copy();
    }
    cout<<round2[0]<<'\n';
}