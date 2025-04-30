#include <bits/stdc++.h>
using namespace std;

int n, k, t;
int a[200010]{}, pre[200010]{};

void ask()
{
    int i;
    cin >> i;
    int j = pre[i];
    while(gcd(a[j],a[i])==1&&j!=0)
    {
        j = pre[j];
    }
    if(j==0)
    {
        cout << "-1" << '\n';
        return;
    }
    cout << j << '\n';
}

void change()
{
    int x, y;
    cin >> x >> y;
    a[x] = y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1,x,y; i < n;i++)
    {
        cin >> x >> y;
        pre[y] = x;
    }
    while(k--)
    {
        cin>>t;
        t == 1 ? ask() : change();
    }
}