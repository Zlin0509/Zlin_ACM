#include<bits/stdc++.h>
using namespace std;

struct node
{
    char l='*';
    char r='*';
};
map<char,node>tree;
int n;

void output(char f)
{
    cout<<f;
    if(tree[f].l!='*')
    {
        output(tree[f].l);
    }
    if(tree[f].r!='*')
    {
        output(tree[f].r);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>n;
    string x;
    char f;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(i==1) f=x[0];
        tree[x[0]].l=x[1];
        tree[x[0]].r=x[2];
    }
    output(f);
}