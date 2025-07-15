//
// Created by Zlin on 2025/1/26.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;


inline void Zlin()
{
    int n, k;
    cin >> n >> k;
    vi R, L;
    for (int i = 0; i < n; ++i)
    {
        int p, v;
        cin >> p >> v;
        if (v == 1)
            R.push_back(p);
        else
            L.push_back(p);
    }
    sort(R.begin(), R.end());
    sort(L.begin(), L.end());
    ll total = 0;
    bool check = false;
    for (int r : R)
    {
        auto it = upper_bound(L.begin(), L.end(), r);
        ll cnt = L.end() - it;
        total += cnt;
        if (total >= k)
        {
            check = true;
            break;
        }
    }
    if (!check)
    {
        cout << "No\n";
        return;
    }
    db left = 0.0, right = 1e18;
    for (int iter = 0; iter < 100; ++iter)
    {
        db mid = (left + right) / 2;
        ll count = 0;
        for (int r : R)
        {
            db max_pos = r + 2 * mid;
            auto low = upper_bound(L.begin(), L.end(), r);
            auto high = upper_bound(L.begin(), L.end(), max_pos);
            count += (high - low);
            if (count >= k) break;
        }
        if (count >= k)
            right = mid;
        else
            left = mid;
    }

    cout << "Yes\n";
    cout << fixed << setprecision(6) << right << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
