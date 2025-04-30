#include <bits/stdc++.h>
using namespace std;

int n, k, ans = INT_MAX;
int used[110][110]{};
struct book
{
    int h;
    int w;
} a[110]{};

bool cmp(const book &a, const book &b)
{
    if (a.h != b.h)
        return a.h < b.h;
    return a.w < b.w;
}

int dfs(int id)
{
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i].h >> a[i].w;
    sort(a + 1, a + 1 + n, cmp);
    dfs(1);
}