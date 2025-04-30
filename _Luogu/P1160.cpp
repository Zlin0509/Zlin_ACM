#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int mx = 1e5 + 10;
int n, m;
struct T
{
    int l, r; // 每个同学的“左右手”
    int d;    // 表示同学是否输出
} t[mx] = {0};
void add(int i, int k, int f) // 新增同学
{
    if (f == 1) // 左
    {
        t[k].r = t[i].r;
        t[k].l = i;
        t[i].r = k;
        t[t[k].r].l = k;
    }
    else // 右
    {
        t[k].r = i;
        t[k].l = t[i].l;
        t[i].l = k;
        t[t[k].l].r = k;
    }
}
int main()
{
    int x, k, f;
    cin >> n;
    t[0].r = 0, t[0].l = 0;
    add(0, 1, 1);
    for (int i = 2; i <= n; i++)
    {
        cin >> x >> f;
        add(x, i, f);
    }
    cin >> m;
    while (m--)
    {
        cin >> x;
        t[x].d = 1; // 将该同学标记为不输出
    }
    for (int i = t[0].r; i; i = t[i].r)
    {
        if (t[i].d == 0) // 输出未标记的
            cout << i << " ";
    }
    return 0;
}