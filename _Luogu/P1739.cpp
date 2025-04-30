#include "bits/stdc++.h"
using namespace std;
#define lowbit(x) (x & (-x))
#define ll long long
#define vi vector<int>
#define vll vector<ll>

char ch;
int n1 = 0, n2 = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> ch;
    while (ch != '@')
    {
        if (ch == '(')
        {
            if (n1 < n2)
            {
                cout << "NO";
                return 0;
            }
            ++n1;
        }
        if (ch == ')')
            ++n2;
        cin >> ch;
    }
    if (n1 != n2)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}