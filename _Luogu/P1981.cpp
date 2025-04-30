#include "bits/stdc++.h"
using namespace std;
#define lowbit(x) (x & (-x))
#define ll long long
#define vi vector<int>
#define vll vector<ll>
const int MOD = 1e4;
string x;
int now = 0, z1, z2;
stack<int> num;
stack<char> z;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> x;
    for (int i = 0; i < x.length(); i++)
    {
        if (isdigit(x[i]))
        {
            now = now * 10 + x[i] - '0';
            now %= MOD;
        }
        else
        {
            num.push(now);
            while (!z.empty() && z.top() == '*')
            {
                z.pop();
                z1 = num.top();
                num.pop();
                z2 = num.top();
                num.pop();
                num.push(z1 * z2 % MOD);
            }
            z.push(x[i]);
            now = 0;
        }
    }
    num.push(now);

    while (!z.empty())
    {
        z1 = num.top();
        num.pop();
        z2 = num.top();
        num.pop();
        if (z.top() == '*')
            num.push(z1 * z2 % MOD);
        else
            num.push((z1 + z2) % MOD);
        z.pop();
    }
    cout << num.top();
    return 0;
}