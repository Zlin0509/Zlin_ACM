#include <bits/stdc++.h>
using namespace std;

char s1[1000010]{}, s2[1000010]{};
int Next[1010]{};

void GetNextval(char *p)
{
    int len = strlen(p);
    Next[0] = -1;
    int k = -1;
    int j = 0;
    while(j<len - 1)
    {
        if (k == -1 || p[j] == p[k])
        {
            ++k;
            ++j;
            if(p[j]!=p[k])
                Next[j] = k;
            else
                Next[j] = Next[k];
        }
        else
        {
            k = Next[k];
        }
    }
}

void GetNext(char *p)
{
    int len = strlen(p);
    Next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < len)
    {
        if (k == -1 || p[j] == p[k])
        {
            ++k;
            ++j;
            Next[j] = k;
        }
        else
        {
            k = Next[k];
        }
    }
}

void KmpSearch(char *s, char *p)
{
    int i = 0;
    int j = 0;
    int sLen = strlen(s);
    int pLen = strlen(p);
    while (i < sLen)
    {
        if (j == -1 || s[i] == p[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = Next[j];
        }
        if (j == pLen)
        {
            cout << i - j + 1 << '\n';
            i = i - j + 1;
            j = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s1 >> s2;
    GetNextval(s2);
    KmpSearch(s1, s2);
    GetNext(s2);

    for (int i = 1; i <= strlen(s2); i++)
    {
        cout << Next[i] << ' ';
    }
}