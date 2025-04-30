#include "bits/stdc++.h"
using namespace std;
#define lowbit(x) (x & (-x))
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 2e5 + 5;
int n, m, ans;
int a[N], M[1500][1500];

void init()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= sqrt(n); j++)
            M[j][i % j] += a[i];
}

void Zlin()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    init();
    char c;
    int x, y;
    while (m--)
    {
        cin >> c >> x >> y;
        if (c == 'A')
        {
            ans = 0;
            if (x > sqrt(n))
                for (int i = y; i <= n; i += x)
                    ans += a[i];
            else
                ans = M[x][y];
            cout << ans << '\n';
        }
        else
        {
            for (int i = 1; i <= sqrt(n); i++)
                M[i][x % i] += y - a[x];
            a[x] = y;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Zlin();
    return 0;
}