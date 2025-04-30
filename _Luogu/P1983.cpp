#include "bits/stdc++.h"
using namespace std;

int n, m, ans = 0, l = 11111, r = 0;
int used[1010]{}, a[1010][1010];
int st[1010]{}, d[1010]{};
int tot = 0, dep[1010];

inline void Zlin()
{
    cin >> n >> m;
    for (int i = 1, s; i <= m; i++)
    {
        memset(used, 0, sizeof used);
        cin >> s;
        for (int i = 1; i <= s; i++)
        {
            cin >> st[i];
            used[st[i]] = 1;
        }
        for (int i = st[1]; i <= st[s]; i++)
            if (!used[i])
            {
                for (int j = 1; j <= s; j++)
                {
                    if (!a[i][st[j]])
                    {
                        ++d[st[j]];
                        ++a[i][st[j]];
                    }
                }
            }
    }
    int top, tt[1010]{};
    memset(used, 0, sizeof used);
    do
    {
        top = 0;
        for (int i = 1; i <= n; i++)
            if (!d[i] && !used[i])
                used[i] = 1, tt[++top] = i;
        for (int i = 1; i <= top; i++)
            for (int j = 1; j <= n; j++)
                if (a[tt[i]][j])
                    --d[j], a[tt[i]][j] = 0;
        ++ans;
    } while (top);
    cout << ans - 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Zlin();
    return 0;
}