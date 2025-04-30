#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200010]{};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        a[i] = a[i - 1] + x;
    }
    cin >> m;
    int l, r;
    while (m--)
    {
        cin >> l >> r;
        cout << a[r] - a[l - 1] << '\n';
    }
}