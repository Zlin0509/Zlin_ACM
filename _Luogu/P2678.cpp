#include<bits/stdc++.h>
using namespace std;

int L, n, m, ans = 0;
int a[50010]{};

bool check(int mid)
{
    int num = 0;
    int i = 0, j = 0;
    while(i<n+1)
    {
        ++i;
        if(a[i]-a[j]<mid)
            ++num;
        else
            j = i;
    }
    if(num>m)
        return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> L >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[n + 1] = L;

    int l = 1, r = L + 1, mid;
    while(l<r)
    {
        mid = l + r >> 1;
        if(check(mid))
            ans = mid, l = mid + 1;
        else
            r = mid;
    }
    cout << ans << '\n';
}