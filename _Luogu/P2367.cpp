#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[5000010]{};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1,x=0,y; i <= n;i++)
    {
        cin >> a[i];
        y = a[i];
        a[i] -= x;
        x = y;
    }
    int l, r, z;
    while(m--)
    {
        cin >> l >> r >> z;
        a[l] += z;
        a[r + 1] -= z;
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n;i++)
    {
        a[i] += a[i - 1];
        ans = min(ans, a[i]);
    }
    cout << ans << '\n';
}