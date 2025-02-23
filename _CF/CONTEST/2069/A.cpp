//
// Created by Zlin on 2025/2/18.
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
    int n;
    cin >> n;
    vi a(n - 2);
    vi b(n, 0);
    int cnt = 0;
    for (int i = 0; i < n - 2; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
        {
            if (b[i])
                b[i + 2] = b[i + 1] = b[i];
            else
                b[i] = b[i + 1] = b[i + 2] = ++cnt;
        }
    }
    for (int i = 0; i < n - 2; i++)
    {
        if (a[i] == 0 && b[i] == b[i + 1] && b[i + 1] == b[i + 2] && b[i] != 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
