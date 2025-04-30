#include "bits/stdc++.h"
using namespace std;
#define lowbit(x) (x & (-x))
#define ll long long
#define vi vector<int>
#define vll vector<ll>

const int N = 5e5 + 10;
int n, k, l, r;
int f[N][33], a[N];

inline void prework()
{
    for (int i = 1; i <= n; i++)
        f[i][0] = a[i];
    
}

inline void Zlin()
{
    cin >> n >> k >> l >> r;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Zlin();
    return 0;
}