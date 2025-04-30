#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, ans;
    cin>>n;
    if(n==1)
    {
        cout<<"1\n";
        return;
    }
    ans = n * (n - 1);
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)
        solve();
}