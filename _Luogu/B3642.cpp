#include <bits/stdc++.h>
using namespace std;

struct node
{
    int l;
    int r;
} tree[1000010];
int n;

void type001(int f)
{
    cout << f << " ";
    if (tree[f].l != 0)
    {
        type001(tree[f].l);
    }
    if (tree[f].r != 0)
    {
        type001(tree[f].r);
    }
}

void type002(int f)
{
    if (tree[f].l != 0)
    {
        type002(tree[f].l);
    }
    cout << f << " ";
    if (tree[f].r != 0)
    {
        type002(tree[f].r);
    }
}

void type003(int f)
{
    if (tree[f].l != 0)
    {
        type003(tree[f].l);
    }
    if (tree[f].r != 0)
    {
        type003(tree[f].r);
    }
    cout << f << " ";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> tree[i].l >> tree[i].r;
    }

    type001(1);
    cout << '\n';
    type002(1);
    cout << '\n';
    type003(1);
}