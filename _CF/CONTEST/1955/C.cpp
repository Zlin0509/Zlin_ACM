#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, k;
    cin >> n >> k;
    deque<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while(a.size() > 1 && k)
    {
        long long ss = min(a.front(), a.back());
        if(k <= ss * 2)
        {
            a.front() -= k / 2 + k % 2;
            a.back() -= k / 2;
            k = 0;
        }
        else
        {
            a.front() -= ss;
            a.back() -= ss;
            k -= ss * 2;
        }
        if(a.front() == 0)
        {
            a.pop_front();
        }
        if(a.back() == 0)
        {
            a.pop_back();
        }
    }
    cout << n - a.size() + (a.size() && a.front() <= k) << '\n';
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