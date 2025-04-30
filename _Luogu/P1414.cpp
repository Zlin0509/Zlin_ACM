#include <bits/stdc++.h>
using namespace std;

int n;
int a[10010]{}, ans[10010]{};
int used[1000010]{};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];

    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= sqrt(a[i]); j++)
        {
            if(a[i]%j==0)
            {
                ++used[j];
                ans[used[j]] = max(ans[used[j]], j);
                if(j*j!=a[i])
                {
                    ++used[a[i] / j];
                    ans[used[a[i] / j]] = max(ans[used[a[i] / j]], a[i] / j);
                }
            }
        }
    }
    for (int i = n - 1; i >= 1; i--)
    {
        ans[i] = max(ans[i], ans[i + 1]);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << '\n';
    }
}