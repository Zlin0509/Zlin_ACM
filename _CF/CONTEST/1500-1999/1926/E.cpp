#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

void solve()
{
    int n, k;
    cin >> n >> k;
    int len1 = n / 2 + n % 2;
    int len = len1;
    int pow = 1;
    while (len < k)
    {
        pow *= 2;
        len1 = n / pow;
        len1 = len1 / 2 + len1 % 2;
        len += len1;
        // cout << len << " " << len1 << '\n';
    }
    len -= len1;
    k -= len;
    cout << (k * 2 - 1) * pow << '\n';
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