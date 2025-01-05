#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
inline void Zlin()
{
    int n, m, len = 0;
    vector<pair<int, int>> ans;
    cin >> n;
    m = n;
    while (m)
    {
        ++len;
        m /= 10;
    }
    int aa[10];
    for (int i = 1; i <= 6 / len; i++)
        m = m * pow(10, len) + n;
    for (int i = 1, j; i <= 5; i++)
    {
        j = pow(10, 6 - i);
        aa[i] = m / j;
    }
    for (int a = 1; a <= 1e6; a++)
    {
        for (int j = 1, b; j <= 5; j++)
        {
            b = n * a - aa[j];
            if (b > 0 && b < min(a * n, 10000) && a * len - j == b)
                ans.push_back({a, b});
        }
    }
    cout << ans.size() << '\n';
    for (auto [x, y] : ans)
        cout << x << ' ' << y << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ttt;
    cin >> ttt;
    while (ttt--)
        Zlin();
}