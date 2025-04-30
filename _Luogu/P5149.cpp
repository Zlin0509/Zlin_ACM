#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x & (-x))

int n;
int a[100001]{};
int Tree[400010]{};
long long ans = 0;

int Trie[500010][100]{};
int tot = 0;
int End[500010]{};

void inserct(int x)
{
    for (int i = x; i <= n; i += lowbit(i))
        ++Tree[i];
}

long long ask(int x)
{
    long long ans = 0;
    for (int i = x - 1; i >= 1; i -= lowbit(i))
        ans += Tree[i];
    return ans;
}

void build(string x, int num)
{
    int u = 0;
    for (int i = 0, y; i < x.length(); i++)
    {
        y = x[i] - 'A';
        if (!Trie[u][y])
            Trie[u][y] = ++tot;
        u = Trie[u][y];
    }
    End[u] = num;
}

int find(string x)
{
    int u = 0;
    for (int i = 0; i < x.length(); i++)
        u = Trie[u][x[i] - 'A'];
    return End[u];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    string x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        build(x, i);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        a[i] = find(x);
    }
    for (int i = n; i >= 1; i--)
    {
        inserct(a[i]);
        ans += ask(a[i]);
    }
    cout << ans << '\n';
}