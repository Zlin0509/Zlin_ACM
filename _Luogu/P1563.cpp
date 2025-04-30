#include<bits/stdc++.h>
using namespace std;

int n, m;
struct people
{
    int tow;
    string name;
} a[100010]{};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n;i++)
        cin >> a[i].tow >> a[i].name;

    int x, y;
    int now = 0;
    while(m--)
    {
        cin >> x >> y;
        if(x==a[now].tow)
        {
            now = (now - y + n) % n;
        }
        else
        {
            now = (now + y + n) % n;
        }
    }
    cout << a[now].name << '\n';
}