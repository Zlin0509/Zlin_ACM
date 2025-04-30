#include <bits/stdc++.h>
using namespace std;

int n, m;
char x[100010]{};
int Trie[1010][5010][26]{}, tot[1010]{};
bool End[1010][5010]{};

inline void Inseart(char *str, int num)
{
    int len = strlen(str), p = 1;
    for (int i = 0; i < len; i++)
    {
        int ch = str[i] - 'a';
        if (Trie[num][p][ch] == 0)
            Trie[num][p][ch] = ++tot[num];
        p = Trie[num][p][ch];
    }
    End[num][p] = true;
}

inline bool Search(char *str, int num)
{
    int len = strlen(str), p = 1;
    for (int i = 0; i < len; i++)
    {
        p = Trie[num][p][str[i] - 'a'];
        if (p == 0)
            return false;
    }
    return End[num][p];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i <= 1000; i++)
        tot[i] = 1;

    cin >> n;
    for (int i = 1, num; i <= n; i++)
    {
        cin >> num;
        for (int j = 1; j <= num; j++)
        {
            cin >> x;
            Inseart(x, i);
        }
    }

    cin >> m;
    while (m--)
    {
        cin >> x;
        for (int i = 1; i <= n; i++)
            if (Search(x, i))
                cout << i << " ";
        cout << '\n';
    }
}