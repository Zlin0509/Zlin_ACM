//
// Created by Zlin on 2025/2/1.
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
    int n, k, z;
    cin >> n >> k >> z;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    db ans = a[0], tag = k;
    for (int i = 1; i < n; i++)
    {
        db now = a[i] - ans;
        if (now >= tag)
        {
            ans += (now - tag) / 2;
            tag = (now + tag) / 2 + k;
        }
        else
        {
            now = a[i] + ans;
            if (now >= tag)
                tag += k;
            else
                tag = max(tag, now + k);
        }
    }
    if (tag < z)
        ans += z - tag;
    cout << int(ans * 2) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
