#include "bits/stdc++.h"
using namespace std;
#define lowbit(x) (x & (-x))
#define ll long long
#define vi vector<int>
#define vll vector<ll>

int n, m, ans = 0, used[100010]{};
queue<int> x;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1, z; i <= m; i++)
    {
        cin >> z;
        if (!used[z])
            ++ans, ++used[z], x.push(z);
        if (x.size() > n)
        {
            used[x.front()]--;
            x.pop();
        }
    }
    cout << ans;
    return 0;
}