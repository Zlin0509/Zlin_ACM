//
// Created by 27682 on 2025/3/14.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 1e6 + 10;

inline void Zlin()
{
    int n;
    cin >> n;
    vi a(n);
    for (int& it : a)
        cin >> it;

    vi xxxx;
    for (int it : a)
        xxxx.push_back(it);
    sort(xxxx.begin(), xxxx.end());
    xxxx.erase(unique(xxxx.begin(), xxxx.end()), xxxx.end());
    for (int& it : a)
        it = lower_bound(xxxx.begin(), xxxx.end(), it) - xxxx.begin();

    vector<vi> q(n + 1);
    vi used(n + 1);
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (!a[i])
            continue;
        q[a[i]].push_back(cnt);
        if (!used[a[i]])
            ++cnt, used[a[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
        used[i] = 0;
    ll ans = 0;
    queue<int> mid;
    for (int it : a)
    {
        if (!it)
        {
            while (!mid.empty())
            {
                int u = mid.front();
                mid.pop();
                if (used[u])
                    continue;
                if (!q[u].empty())
                    ans += q[u].back();
                used[u] = 1;
            }
        }
        else
        {
            mid.push(it);
            q[it].pop_back();
        }
    }
    cout << ans << endl;
}

int main()
{
    int size(256 << 20); // 256M
    __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size) + size));
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    exit(0);
}
