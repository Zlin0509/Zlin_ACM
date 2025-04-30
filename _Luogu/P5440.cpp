#include<bits/stdc++.h>
using namespace std;
int n, a[9], prim[10005], flag[10005], tot;
char tmpc;
int p10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
int yue[] = {0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1};
inline void init()
{
    flag[1] = 1;
    for (int i = 2; i < 10005; i++)
    {
        if (!flag[i])
            prim[++tot] = i;
        for (int j = 1; j <= tot; j++)
        {
            if (i * prim[j] >= 10005)
                break;
            flag[i * prim[j]] = 1;
            if (i % prim[j] == 0)
                break;
        }
    }
    return;
}
inline int pdrn(int x)
{
    return (x % 4 == 0 && x % 100 != 0) || (x % 400 == 0 && x % 3200 != 0);
}
inline int pdzs(int x)
{
    if (x < 2)
        return 0;
    for (int i = 1; i <= tot; i++)
        if (x % prim[i] == 0)
            return x == prim[i];
    return 1;
}
int dfs(int nown, int num, int rn, int jy)
{
    if (nown == 0)
    {
        if (num / 10000 == 0)
            return 0;
        if (rn && pdrn(num / 10000) == 0)
            return 0;
        return pdzs(num);
    }
    if (nown == 6)
    {
        if (num == 0 || num > 31 || !pdzs(num))
            return 0;
        if (num == 31)
            jy = 1;
    }
    if (nown == 4)
    {
        if (num < 32 || num > 1231 || !pdzs(num))
            return 0;
        if (jy && !yue[num / 100])
            return 0;
        if (num / 100 == 2)
        {
            if (num % 100 > 29)
                return 0;
            if (num % 100 == 29)
                rn = 1;
        }
    }
    if (a[nown] != -1)
        return dfs(nown - 1, a[nown] * p10[8 - nown] + num, rn, jy);
    int res = 0;
    for (int i = 0; i <= 9; i++)
        res += dfs(nown - 1, i * p10[8 - nown] + num, rn, jy);
    return res;
}
char get()
{
    char ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '-')
        ch = getchar();
    return ch;
}
void put(int x)
{
    if (x > 9)
        put(x / 10);
    putchar('0' + x % 10);
    return;
}
int main()
{
    init(), cin >> n;
    while (n--)
    {
        for (int i = 1; i <= 8; i++)
            tmpc = get(), a[i] = (tmpc == '-' ? -1 : tmpc - '0');
        put(dfs(8, 0, 0, 0)), putchar('\n');
    }
    return 0;
}