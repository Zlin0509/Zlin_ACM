#include <bits/stdc++.h>
using namespace std;
string s;
long long n, num, i;
int main()
{
    cin >> s >> n;
    num = s.length();
    while (num < n)
    {
        i = num;
        while (n > i)
            i *= 2;
        i = i / 2; 
        n -= (i + 1);
        if (n == 0)
            n = i;
    }
    cout << s[n - 1];
}