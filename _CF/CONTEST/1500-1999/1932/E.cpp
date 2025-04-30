#include <bits/stdc++.h>
#define long long long int
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        vector<int> a(n + 1);
        for (int i = n - 1; i >= 0; i--)
        {
            a[i] = a[i + 1] + (s[i] - '0');
        }
        string res;
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            c += a[i];
            res += (char)(c % 10 + '0');
            c /= 10;
        }
        res += (char)(c + '0');
        while (res.back() == '0')
        {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        cout << res << "\n";
    }

    return 0;
}