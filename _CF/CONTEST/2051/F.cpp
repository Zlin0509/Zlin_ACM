//
// Created by Zlin on 2025/2/22.
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
    int n, m, q;
    cin >> n >> m >> q;
    vi tag(n + 1);
    int ans = 1;
    tag[m] = 1;
    while (q--)
    {
        int x;
        cin >> x;
        if (tag[x])
        {
            tag[x] = 0;
            --ans;
            if (!tag[1])
                tag[1] = 1, ++ans;
            if (!tag[n])
                tag[n] = 1, ++ans;
        }

        cout << ans << ' ';
    }
    cout << endl;
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
