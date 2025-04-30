#include "bits/stdc++.h"
using namespace std;
#define lowbit(x) (x & (-x))
#define ll long long
#define vi vector<int>
#define vll vector<ll>
char ch;
int now = 0, n = 0, s[200010]{};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> ch;
    while (ch != '@')
    {
        if (isdigit(ch))
        {
            now = now * 10 + ch - '0';
        }
        else if (ch == '.')
        {
            s[++n] = now;
            now = 0;
        }
        else if (ch == '+')
        {
            s[n - 1] += s[n];
            --n;
        }
        else if (ch == '-')
        {
            s[n - 1] -= s[n];
            --n;
        }
        else if (ch == '*')
        {
            s[n - 1] *= s[n];
            --n;
        }
        else
        {
            s[n - 1] /= s[n];
            --n;
        }
        cin >> ch;
    }
    cout << s[1];
    return 0;
}