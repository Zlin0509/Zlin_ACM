#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n, m;
int a[11][11]{};

void Zlin()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    if (n == 1 && m == 1)
    {
        cout << "-1\n";
        return;
    }
    if (m > 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << a[i][m] << ' ';
            for (int j = 1; j < m; j++)
                cout << a[i][j] << ' ';
            cout << '\n';
        }
        return;
    }
    for (int i = 1; i <= m; i++)
        cout << a[n][m] << ' ';
    cout << '\n';
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
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