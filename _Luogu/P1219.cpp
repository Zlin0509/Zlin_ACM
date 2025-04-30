#include <bits/stdc++.h>
using namespace std;

int n, num = 0;
int a[150]{}, b[150]{};
int x[150]{}, y[150]{};

void output()
{
    if(num<=2)
    {
        for (int i = 1; i <= n;i++)
        {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
    ++num;
}

void dfs(int depth)
{
    if(depth>n)
    {
        output();
        return;
    }
    for (int i = 1; i <= n;i++)
    {
        if((!b[i])&&(!x[i+depth])&&(!y[depth - i + n]))
        {
            a[depth] = i;
            b[i] = 1;
            x[depth + i] = 1;
            y[depth - i + n] = 1;
            dfs(depth + 1);
            b[i] = 0;
            x[depth + i] = 0;
            y[depth - i + n] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    dfs(1);
    cout << num << '\n';
}