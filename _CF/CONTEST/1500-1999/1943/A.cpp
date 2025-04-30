#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

void solve()
{
    int n;
    cin>>n;
    vi a(n + 1), b(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ++b[a[i]];
    }
    int num = 0;
    for (int i = 0; i <= n; i++)
    {
        num += (b[i] == 1);
        if(num==2||b[i]==0)
        {
            cout << i << '\n';
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}