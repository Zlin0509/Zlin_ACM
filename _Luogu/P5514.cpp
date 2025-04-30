#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, a;
    int num[65]{},ans=0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        ans ^= a;
    }
    cout << ans << '\n';
}