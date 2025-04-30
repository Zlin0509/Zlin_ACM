#include <bits/stdc++.h>
using namespace std;

int l, ans;
string x;
int Next[1000010]{};

inline void make_next()
{
    int len = x.length();
    Next[1] = 0;
    for (int i = 2, j = 0; i < len; i++)
    {
        while (j > 0 && x[i] != x[j + 1])
            j = Next[j];
        if (x[i] == x[j + 1])
            ++j;
        Next[i] = j;
    }
}

inline void Find()
{
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    x += ',';
    cin >> l >> x;
    x += x;
    ans = l;

    make_next();


    cout << ans << '\n';
}