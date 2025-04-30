#include<bits/stdc++.h>
using namespace std;

struct node
{
    long long l, r;
} a[200010]{};
int n;

bool cmp(const node &a,const node &b)
{
    if(a.l!=b.l)
        return a.l < b.l;
    return a.r < b.r;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for (int i = 0; i < n;i++)
    {
        cin >> a[i].l >> a[i].r;
    }
    sort(a, a + n, cmp);
    
}