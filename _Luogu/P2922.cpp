#include <bits/stdc++.h>
using namespace std;

int m, n;
int Trie[500010][3]{};
int num[500010]{}, End[500010]{};
int tot = 0;

void build()
{
    int len, u = 0;
    cin >> len;
    for (int i = 1, j; i <= len; i++)
    {
        cin >> j;
        if (!Trie[u][j])
            Trie[u][j] = ++tot;
        u = Trie[u][j];
        ++num[u];
    }
    ++End[u];
}

void search()
{
    int len, u = 0, check = 0;
    cin >> len;
    bool flag = true;
    vector<int> c;
    for (int i = 1, j; i <= len; i++)
    {
        cin >> j;
        c.push_back(j);
    }
    for (int i = 1, j; i <= len; i++)
    {
        j = c[i - 1];
        if (!Trie[u][j])
        {
            cout << check << '\n';
            return;
        }
        u = Trie[u][j];
        check += End[u];
    }
    cout << num[u] + check - End[u] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        build();
    for (int i = 1; i <= n; i++)
        search();
}