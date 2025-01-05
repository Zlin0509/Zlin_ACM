#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    if (a * 2 > b)
    {
        cout << n / 2 * b + n % 2 * a << '\n';
        return;
    }
    cout << a * n << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}