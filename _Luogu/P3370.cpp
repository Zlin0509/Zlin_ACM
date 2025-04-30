#include <bits/stdc++.h>
using namespace std;

long long base = 111;
long long prime = 233;
long long Mod = 1e12;

long long Hash(string x)
{
    int len = x.length();
    long long ans = 0;
    for (int i = 0; i < len; i++)
    {
        ans = (ans * base + (long long)x[i]) % Mod + prime;
    }
    return ans;
}

long long a[100010]{};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        a[i] = Hash(x);
    }

    sort(a + 1, a + 1 + n);
    int ans = 1;
    for (int i = 1; i < n; i++)
        if (a[i] != a[i + 1])
            ++ans;
    cout << ans;
}