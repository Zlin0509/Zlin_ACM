#include<bits/stdc++.h>
using namespace std;

int m,n;
char ma[2010][2010]{};
int k,l;
int a[55][55]{};

//绘制单体
void write(int x,int y)
{
    ma[x][y]='+';ma[x+4][y]='+';ma[x+6][y+2]='+';ma[x+6][y+5]='+';ma[x][y+3]='+';ma[x+4][y+3]='+';ma[x+2][y+5]='+';
    for(int i=1;i<=3;i++)
    {
        ma[x+i][y]=ma[x+i][y+3]=ma[x+i+2][y+5]='-';
    }
    for(int i=1;i<=2;i++)
    {
        ma[x][y+i]=ma[x+4][y+i]=ma[x+6][y+i+2]='|';
    }
    ma[x+1][y+4]='/';ma[x+5][y+4]='/';ma[x+5][y+1]='/';

    for(int i=1;i<=3;i++)
    {
        ma[x+i][y+1]=ma[x+i][y+2]=ma[x+i+1][y+4]='1';
    }
    ma[x+5][y+2]=ma[x+5][y+3]='1';
    //‘1’表示为表面，输出时为空格;
}

void output()
{
    for(int i=k;i>=1;i--)
    {
        for(int j=1;j<=l;j++)
        {
            if(ma[i][j]=='\0')
            {
                cout<<".";
            }
            else if(ma[i][j]=='1')
            {
                cout<<" ";
            }
            else
            {
                cout<<ma[i][j];
            }
        }
        cout<<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>m>>n;
    for(int i=m-1;i>=0;i--)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }

    int x,y;
    for(int i=m-1;i>=0;i--)
    {
        for(int j=0;j<n;j++)
        {
            for(int q=0;q<a[i][j];q++)
            {
                x=1+i*2+j*4;
                y=1+i*2+q*3;
                write(x,y);
                k=max(k,y+5);
                l=max(l,x+6);
            }
        }
    }
    output();
}