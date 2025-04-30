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

int n, k;

inline void Zlin()
{
    int N, K;
    cin >> N >> K;
    int L = 1, R = N;
    int val = 0, vtot = 0;
    while (L <= R)
    {
        int mid = (L + R) / 2;
        int tot = 0;
        for (int l = 1, r; l <= N; l = r + 1)
        {
            r = N / (N / l);
            int a = N - N / l * l;
            int k = (N / l);
            if (a < mid)
                continue;
            tot += min((a - mid) / k + 1, r - l + 1);
        }
        if (tot >= K)
        {
            L = mid + 1;
        }
        else
        {
            vtot = tot;
            val = mid;
            R = mid - 1;
        }
    }
    ll ans = 1LL * (K - vtot) * (val - 1);
    for (int l = 1, r; l <= N; l = r + 1)
    {
        r = N / (N / l);
        int a = N - N / l * l;
        int k = (N / l);
        if (a < val)
            continue;
        int len = min((a - val) / k + 1, r - l + 1);
        ans += 1LL * (a * 2 - k * (len - 1)) * len / 2;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
