#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
int n, x, y, l, r;
int a[200010]{};
void Zlin()
{
    cin >> n >> x >> y;
    if (x <= y)
    {
        for (int i = x + 1; i <= y - 1; i++)
            a[i] = -1;

        for (int i = x; i >= 1; i--)
            (x - i + 1) & 1 ? a[i] = 1 : a[i] = -1;
        for (int i = y; i <= n; i++)
            (i - y + 1) & 1 ? a[i] = 1 : a[i] = -1;
    }
    else
    {
        for (int i = y - 1; i > 0; i--)
            (y - i) & 1 ? a[i] = -1 : a[i] = 1;
        for (int i = x + 1; i <= n; i++)
            (i - x) & 1 ? a[i] = -1 : a[i] = 1;
        for (int i = y; i <= x; i++)
            a[i] = 1;
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    cout << '\n';
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