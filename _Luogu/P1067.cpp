#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    int a[110]{};
    cin >> n;
    for (int i = 0; i <= n; i++)
        cin >> a[i];

    if(n==0)
    {
        cout << a[0];
        return 0;
    }

    if (a[0] != 0)
    {
        if (a[0] == -1)
            cout << "-";
        else if (a[0] != 1)
            cout << a[0];
        cout << "x^" << n;
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i] != 0)
        {
            if (a[i] > 0)
                cout << "+";
            if (a[i] == -1)
                cout << "-";
            if (a[i] != 1 && a[i] != -1)
                cout << a[i];
            cout << "x^" << n - i;
        }
    }
    if (a[n - 1] != 0)
    {
        if (a[n - 1] > 0)
            cout << "+";
        if (a[n - 1] == -1)
            cout << "-";
        if (a[n - 1] != 1 && a[n - 1] != -1)
            cout << a[n - 1];
        cout << "x";
    }
    if (a[n] != 0)
    {
        if (a[n] > 0)
            cout << "+";
        cout << a[n];
    }
}