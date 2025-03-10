#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n;
char x[30];

void solve()
{
    bool check = false;
    char m = '0';
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
    {
        if (x[i] <= '9' && x[i] >= '0')
        {
            if (check || x[i] < m)
            {
                cout << "NO" << '\n';
                return;
            }
            m = x[i];
        }
        else
        {
            if (!check)
                m = x[i];
            else
            {
                if (x[i] < m)
                {
                    cout << "NO" << '\n';
                    return;
                }
                m = x[i];
            }
            check = true;
        }
    }
    cout << "YES" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
        solve();
}