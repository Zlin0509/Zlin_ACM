//
// Created by Zlin on 2025/1/18.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

struct node
{
    int x, y;
};

vector<node> a;

int n, m, k;
vector<vector<bool>> tag;

inline void init()
{
    a.assign(n + 1, {0, 0});
    tag.assign(n + 1, vector<bool>(m + 1, false));
}

inline void Zlin()
{
    cin >> n >> m >> k;
    init();
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;
    auto check_in = [&](node s, int r, int x, int y)
    {
        ll dx = abs(s.x - x), dy = abs(s.y - y);
        ll rr = 1ll * r * r;
        return rr >= dx * dx + dy * dy;
    };
    for (int i = 1, r, x, y; i <= m; i++)
    {
        cin >> r >> x >> y;
        for (int j = 1; j <= n; j++)
            tag[j][i] = check_in(a[j], r, x, y);
    }
    int l, r, ans;
    while (k--)
    {
        cin >> l >> r;
        ans = 0;
        for (int i = 1; i <= m; i++)
            ans += tag[l][i] != tag[r][i];
        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
