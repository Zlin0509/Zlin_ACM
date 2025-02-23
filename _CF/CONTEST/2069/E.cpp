#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int a, b, ab, ba;
        cin >> a >> b >> ab >> ba;

        int n = s.size();
        int cntA = 0, cntB = 0;
        for (char c : s)
        {
            if (c == 'A') cntA++;
            else cntB++;
        }

        int need = max({cntA - a, cntB - b, 0});


        int totalPairs = 0;
        int forcedA = 0, forcedB = 0;

        int i = 0;
        while (i < n)
        {
            int j = i;
            while (j + 1 < n && s[j + 1] != s[j])
                j++;
            int len = j - i + 1;
            if (len >= 2)
            {
                totalPairs += len / 2;
                if (len % 2 == 0)
                {
                    if (s[i] == 'A')
                        forcedA++;
                    else
                        forcedB++;
                }
            }
            i = j + 1;
        }

        if (need > totalPairs)
        {
            cout << "NO" << "\n";
            continue;
        }

        int slack = totalPairs - need;

        int dropNeeded = max(0, forcedA - ab) + max(0, forcedB - ba);

        if (slack >= dropNeeded)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }

    return 0;
}
