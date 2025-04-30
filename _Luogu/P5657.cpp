#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    unsigned long long n, m;
    cin >> n >> m;
    m ^= m >> 1;
    while(n--)
    {
        cout << (m >> n & 1);
    }
}