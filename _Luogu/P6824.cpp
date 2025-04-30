#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n, k;
int Trie[21000][2]{};
int num[21000]{};
int tot = 0;

void build(int x)
{
    int u = 0;
    for (int i = 21, y; i >= 1; i--)
    {
        y = x ^ (1 << i);
        if (!Trie[u][y])
            Trie[u][y] = ++tot;
        u = Trie[u][y];
        ++num[u];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1, y; i <= n; i++)
    {
        cin >> y;
        build(y);
    }
}