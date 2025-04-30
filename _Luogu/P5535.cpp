#include <bits/stdc++.h>
using namespace std;

long long n, k;

bool check(long long x)
{
    if(x==1)
        return 0;
    if(x==2)
        return 1;
    for (int i = 2; i <= sqrt(x);i++)
    {
        if(x%i==0)
            return 0;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    if(check(k + 1)&&k*2>=n)
    {
        cout << '1' << '\n';
    }
    else
    {
        cout << '2' << '\n';
    }
}