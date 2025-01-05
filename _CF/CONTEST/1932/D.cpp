#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

void solve()
{
    int n;
    cin >> n;
    char w;
    cin >> w;
    map<char, vi> p;
    for (int i = 0; i < n * 2; i++)
    {
        int x;
        char y;
        cin >> x >> y;
        p[y].push_back(x);
        // cout << p[y][0] << endl;
    }
    char a[4] = {'C', 'D', 'H', 'S'};
    int num = 0;
    for (int i = 0; i < 4; i++)
    {
        sort(p[a[i]].begin(), p[a[i]].end());
        if (a[i] != w && !p[a[i]].empty())
        {
            // cout << p[a[i]].size() << " " << a[i] << '\n';
            num += p[a[i]].size() % 2;
            // cout << num << '\n';
        }
    }
    if ((!p[w].empty() && (p[w].size() - num) % 2) || p[w].size() < num)
    {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    if (p[w].empty() && num)
    {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    int l = 0;
    for (int i = 0; i < 4; i++)
    {
        if (a[i] != w && !p[a[i]].empty())
        {
            for (int j = 2; j < p[a[i]].size() + 1; j += 2)
            {
                cout << p[a[i]][j - 2] << a[i] << ' ' << p[a[i]][j - 1] << a[i] << '\n';
            }
            if (p[a[i]].size() % 2)
            {
                cout << *(p[a[i]].end() - 1) << a[i] << ' ' << p[w][l++] << w << '\n';
            }
        }
    }
    for (l; l < p[w].size(); l += 2)
    {
        cout << p[w][l] << w << ' ' << p[w][l + 1] << w << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}